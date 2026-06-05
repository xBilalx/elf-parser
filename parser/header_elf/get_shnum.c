#include "header_elf.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/convert.h"

int get_shnum(struct elf_info_struct* elfi) {
    elfi->shnum = read_elf_u16(elfi);
    printf("Size of a Section header table entry:  0x%x\n", elfi->shnum);
    return 1;
}