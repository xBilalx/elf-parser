#include "../header_elf.h"

#include "../../../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../../include/convert.h"

int entry_uint32(struct elf_info_struct *elfi)
{
    elfi->entry_uint32 = read_elf_u32(elfi);

    printf("Version: CURRENT (0x%x)\n", elfi->entry_uint32);
    return 1;
}