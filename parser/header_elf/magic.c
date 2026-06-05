#include "header_elf.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int magic_elf(struct elf_info_struct* elfi) {
    if (elfi->elf_header[EI_MAG0] != ELFMAG0)
        return 0;
    if (elfi->elf_header[EI_MAG1] != ELFMAG1)
        return 0;
    if (elfi->elf_header[EI_MAG2] != ELFMAG2)
        return 0;
    if (elfi->elf_header[EI_MAG3] != ELFMAG3)
        return 0;
    printf("Format File : Executable and Linkable Format (ELF).\n");
    return 1;
}