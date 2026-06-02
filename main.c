#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "./include/elf.h"
#include "./parser/parser.h"

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

    if (read(elfi->fd, elfi->elf_header, EI_NIDENT) != EI_NIDENT) {
        fprintf(stderr, "Error: [MAGIC_ELF] Not ELF FILE.");
        return 84;
    }

    // ELF FILE PARSER
    if (magic_elf(elfi) == 0) {
        fprintf(stderr, "Error: [MAGIC_ELF] Not ELF FILE.");
        close(elfi->fd);
        return 84;
    }
    if (class_elf(elfi) == 0) {
        fprintf(stderr, "Error: [CLASS_ELF] Class didn't find.");
        close(elfi->fd);
        return 84;
    }
    if (data_elf(elfi) == 0) {
        fprintf(stderr, "Error: [DATA_ELF] Invalid Data Encoding.");
        close(elfi->fd);
        return 84;
    }
    if (etype_elf(elfi) == 0) {
        fprintf(stderr, "Error: [DATA_ELF] Invalid Data Encoding.");
        close(elfi->fd);
        return 84;
    }
    
    // CLEAN PROCESS
    close(elfi->fd);
    free(elfi);
    return 0;
}