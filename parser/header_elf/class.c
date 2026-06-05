#include "header_elf.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int class_elf(struct elf_info_struct* elfi) {
    switch (elfi->elf_header[EI_CLASS])
    {
    case ELFCLASS32:
        printf("32Bits\n");
        elfi->elf_class = ELFCLASS32;
        return 1;
    case ELFCLASS64:
        printf("64Bits\n");
        elfi->elf_class = ELFCLASS64;
        return 1;
    default:
        return 0;
    }
    return 1;
}