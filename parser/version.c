#include "parser.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/convert.h"

int version_elf(struct elf_info_struct *elfi)
{
    elfi->elf_version = read_elf_u32(elfi);

    if (elfi->elf_version != EV_CURRENT) {
        fprintf(stderr, "Invalid ELF version: %u\n", elfi->elf_version);
        return 0;
    }

    printf("Version: CURRENT (%u)\n", elfi->elf_version);
    return 1;
}