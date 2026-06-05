#include "../header_elf.h"

#include "../../../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../../include/convert.h"

int shoff_uint64(struct elf_info_struct *elfi)
{
    elfi->shoff_uint64 = read_elf_u64(elfi);

    printf("Section Header Offset:  0x%lx\n", elfi->shoff_uint64);
    return 1;
}