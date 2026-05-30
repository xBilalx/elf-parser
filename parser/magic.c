#include "parser.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int check_if_elf(char *ident) {
    if (ident[EI_MAG0] != ELFMAG0)
        return 0;
    if (ident[EI_MAG1] != ELFMAG1)
        return 0;
    if (ident[EI_MAG2] != ELFMAG2)
        return 0;
    if (ident[EI_MAG3] != ELFMAG3)
        return 0;
    printf("Format File : Executable and Linkable Format (ELF).\n");
    return 1;
}

int magic_elf(struct elf_info_struct* elfi) {
    char *buff;
    int i = 0;
    int return_value = 0;
    int size = (EI_MAG3 + 1) - elfi->current_index;

    buff = malloc(sizeof(char) * size);
    i = read(elfi->fd, buff, size);
    elfi->current_index += size;
    if (i != size) {
        printf("Le fichier n'est pas un fichier ELF.");
        return 0;
    }
    return_value = check_if_elf(buff);
    free(buff);
    return return_value;
}