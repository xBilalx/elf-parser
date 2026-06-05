#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "./include/elf.h"
#include "./parser/header_elf/header_elf.h"

int init_elf_info(elf_info_t *elfi)
{
    if (elfi == NULL)
        return 0;

    elfi->fd = -1;

    elfi->elf_header = malloc(sizeof(unsigned char) * EI_NIDENT);
    if (elfi->elf_header == NULL)
        return 0;

    memset(elfi->elf_header, 0, EI_NIDENT);

    elfi->elf_class = ELFCLASSNONE;
    elfi->elf_data = ELFDATANONE;
    elfi->elf_etype = ET_NONE;
    elfi->elf_emachine = EM_NONE;
    elfi->elf_version = EV_NONE;

    elfi->entry_uint64 = 0;
    elfi->phoff_uint64 = 0;
    elfi->shoff_uint64 = 0;

    elfi->entry_uint32 = 0;
    elfi->phoff_uint32 = 0;
    elfi->shoff_uint32 = 0;
    
    elfi->ehsize = 0;
    elfi->phentsize = 0;
    elfi->phnum = 0;

    return 1;
}

int cleanup_error(struct elf_info_struct *elfi, const char *msg)
{
    if (msg)
        fprintf(stderr, "%s\n", msg);
    if (elfi) {
        if (elfi->fd != -1)
            close(elfi->fd);
        free(elfi->elf_header);
        free(elfi);
    }
    exit(84);
}

int main (int argv, char *argc[]) {
    struct elf_info_struct* elfi = NULL;
    
    elfi = malloc(sizeof(struct elf_info_struct));
    init_elf_info(elfi);
    unsigned int eflag;
    // VERIFICATION FILE
    if (argv <= 1) {
        printf("Veuillez indiquer le nom du fichier.");
        return 84;
    }
    elfi->fd = open(argc[1], O_RDONLY);
    if (elfi->fd == -1) {
        printf("Le fichier est introuvable.");
        return 84;
    }

    if (read(elfi->fd, elfi->elf_header, EI_NIDENT) != EI_NIDENT) {
        cleanup_error(elfi, "Error: [MAGIC_ELF 1] Not ELF FILE.");
    }
    // ELF FILE PARSER
    if (magic_elf(elfi) == 0)
        cleanup_error(elfi, "Error: [MAGIC_ELF 2] Not ELF FILE.");
    if (class_elf(elfi) == 0)
        cleanup_error(elfi, "Error: [CLASS_ELF] Class didn't find.");
    if (data_elf(elfi) == 0)
        cleanup_error(elfi, "Error: [TYPE_ELF] Invalid Data encoding.");
    if (etype_elf(elfi) == 0)
        cleanup_error(elfi, "Error: [TYPE_ELF] Invalid Type Value.");
    if (etmachine_elf(elfi) == 0)
        cleanup_error(elfi, "Error: [MACHINE_ELF] Invalid Machine Value.");
    if (version_elf(elfi) == 0)
        cleanup_error(elfi, "");

    if (elfi->elf_class == ELFCLASS32) {
        // 32 bytes parser
        entry_uint32(elfi);
        phoff_uint32(elfi);
        shoff_uint32(elfi);
        read(elfi->fd, &eflag, 4); // Usefull to read e_flags
    } else if (elfi->elf_class == ELFCLASS64) {
        // 64 bytes parser
        entry_uint64(elfi);
        phoff_uint64(elfi);
        shoff_uint64(elfi);
        read(elfi->fd, &eflag, 4); // Usefull to read e_flags
    }
    get_ehsize(elfi);
    get_phentsize(elfi);
    get_phnum(elfi);
    get_shentsize(elfi);
    get_shnum(elfi);
    get_shstrndx(elfi);
    // CLEAN PROCESS
    close(elfi->fd);
    free(elfi);
    return 0;
}
