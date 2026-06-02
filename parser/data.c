#include "parser.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int data_elf(struct elf_info_struct* elfi) {
    switch (elfi->elf_header[EI_DATA])
    {
    case ELFDATA2LSB:
        printf("Data: Little endian\n");
        elfi->elf_data = ELFDATA2LSB;
        return 1;
    case ELFDATA2MSB:
        printf("Data: Big endian non pris en charge pour le moment.\n");
        elfi->elf_data = ELFDATA2MSB;
        return 1;
    case ELFDATANONE:

        elfi->elf_data = ELFDATANONE;
        return 0;
    default:
        return 0;
    }
    return 1;
}