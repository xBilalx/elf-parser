#include "../header_elf.h"

#include "../../../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../../include/convert.h"

int phoff_uint32(struct elf_info_struct *elfi)
{
    elfi->phoff_uint32 = read_elf_u32(elfi);

    printf("Program Header Offset:  0x%x\n", elfi->phoff_uint32);
    return 1;
}