#include "header_elf.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/convert.h"

int get_shstrndx(struct elf_info_struct* elfi) {
    elfi->shstrndx = read_elf_u16(elfi);
    printf("Index of section header who contains the section names:  0x%x\n", elfi->shstrndx);
    return 1;
}