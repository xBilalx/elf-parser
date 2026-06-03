#include "parser.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/convert.h"
// #include "../include/elf_info.h"

int etype_elf(struct elf_info_struct* elfi) {
    
    elfi->elf_etype = read_elf_u16(elfi);

    switch (elfi->elf_etype) {
        case ET_NONE:
            printf("Type: NONE (No file type)\n");
            break;

        case ET_REL:
            printf("Type: REL (Relocatable file)\n");
            break;

        case ET_EXEC:
            printf("Type: EXEC (Executable file)\n");
            break;

        case ET_DYN:
            printf("Type: DYN (Shared object file)\n");
            break;

        case ET_CORE:
            printf("Type: CORE (Core file)\n");
            break;

        default:
            fprintf(stderr, "Unknown ELF type: %u\n", elfi->elf_etype);
            return 0;
    }
    return 1;
}