#include "parser.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/convert.h"

int etype_elf(struct elf_info_struct* elfi) {
    unsigned char *buf = malloc(sizeof(char) * 2);
    if (read(elfi->fd, buf, 2) != 2) {
        return 0;
    }
    unsigned short value_type = convert_uint16(buf, elfi->elf_data);

    switch (value_type) {
        case ET_NONE:
            elfi->elf_etype = ET_NONE;
            printf("Type: NONE (No file type)\n");
            break;

        case ET_REL:
            elfi->elf_etype = ET_REL;
            printf("Type: REL (Relocatable file)\n");
            break;

        case ET_EXEC:
            elfi->elf_etype = ET_EXEC;
            printf("Type: EXEC (Executable file)\n");
            break;

        case ET_DYN:
            elfi->elf_etype = ET_DYN;
            printf("Type: DYN (Shared object file)\n");
            break;

        case ET_CORE:
            elfi->elf_etype = ET_CORE;
            printf("Type: CORE (Core file)\n");
            break;

        default:
            fprintf(stderr, "Unknown ELF type: %u\n", value_type);
            return 0;
    }
    return 1;
}