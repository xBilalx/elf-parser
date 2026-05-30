#include "parser.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int check_class(char *ident, struct elf_info_struct* elfi) {
    switch (ident[0])
    {
    case ELFCLASS32:
        printf("32Bits\n");
        break;
    case ELFCLASS64:
        printf("64Bits\n");
        break;
    default:
        break;
    }
    return 1;
}

int class_elf(struct elf_info_struct* elfi) {
    char *buff;
    int i = 0;
    int return_value = 0;
    int size = (EI_CLASS + 1) - elfi->current_index;

    buff = malloc(sizeof(char) * size);
    i = read(elfi->fd, buff, size);
    elfi->current_index += size;
    if (i != size) {
        printf("Le fichier n'est pas un fichier ELF.");
        return 0;
    }
    check_class(buff, elfi);
    free(buff);
    return return_value;
}