#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "./include/elf.h"
#include "./parser/parser.h"

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
    return 84;
}

int main (int argv, char *argc[]) {
    struct elf_info_struct* elfi = NULL;
    unsigned char test = 1;
    
    elfi = malloc(sizeof(struct elf_info_struct));
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

    elfi->elf_header = malloc(sizeof(unsigned char) * EI_NIDENT);
    elfi->elf_etype = ET_NONE;
    elfi->elf_emachine = EM_NONE;
    elfi->elf_data = ELFDATANONE;
    elfi->elf_class = ELFCLASSNONE;

    if (read(elfi->fd, elfi->elf_header, EI_NIDENT) != EI_NIDENT) {
        fprintf(stderr, "Error: [MAGIC_ELF] Not ELF FILE.");
        return 84;
    }
    // ELF FILE PARSER
    if (magic_elf(elfi) == 0)
        cleanup_error(elfi, "Error: [MAGIC_ELF] Not ELF FILE.");
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

    } else if (elfi->elf_class == ELFCLASS64) {
        // 64 bytes parser
    } 
    
    // CLEAN PROCESS
    close(elfi->fd);
    free(elfi);
    return 0;
}
