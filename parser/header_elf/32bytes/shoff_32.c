#include "../header_elf.h"

#include "../../../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../../include/convert.h"

int shoff_uint32(struct elf_info_struct *elfi)
{
    elfi->shoff_uint32 = read_elf_u32(elfi);

    printf("Section Header Offset:  0x%x\n", elfi->shoff_uint32);
    return 1;
}
