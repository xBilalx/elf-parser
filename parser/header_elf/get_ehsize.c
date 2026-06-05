#include "header_elf.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/convert.h"
// #include "../include/elf_info.h"

int get_ehsize(struct elf_info_struct* elfi) {
    
    elfi->ehsize = read_elf_u16(elfi);
    printf("ELF Header size:  0x%x\n", elfi->ehsize);

    return 1;
}