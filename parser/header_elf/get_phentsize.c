#include "header_elf.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/convert.h"

int get_phentsize(struct elf_info_struct* elfi) {
    elfi->phentsize = read_elf_u16(elfi);
    printf("Size of a program header table entry:  0x%x\n", elfi->phentsize);
    return 1;
}