#include "header_elf.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/convert.h"

int get_phnum(struct elf_info_struct* elfi) {
    elfi->phnum = read_elf_u16(elfi);
    printf("Number of Program header table entry:  0x%x\n", elfi->phnum);
    return 1;
}