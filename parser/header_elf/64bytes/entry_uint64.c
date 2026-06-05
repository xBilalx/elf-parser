#include "../header_elf.h"

#include "../../../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../../include/convert.h"

int entry_uint64(struct elf_info_struct *elfi)
{
    elfi->entry_uint64 = read_elf_u64(elfi);

    printf("Version: CURRENT (0x%lx)\n", elfi->entry_uint64);
    return 1;
}