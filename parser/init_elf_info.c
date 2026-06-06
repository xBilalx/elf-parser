#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "../include/elf.h"
#include "../include/elf_info.h"
#include "parser.h"

int init_elf_info(elf_info_t *elfi)
{
    if (elfi == NULL)
        return 0;

    elfi->fd = -1;

    elfi->elf_header = malloc(sizeof(unsigned char) * EI_NIDENT);
    if (elfi->elf_header == NULL)
        return 0;

    memset(elfi->elf_header, 0, EI_NIDENT);

    elfi->elf_class = ELFCLASSNONE;
    elfi->elf_data = ELFDATANONE;
    elfi->elf_etype = ET_NONE;
    elfi->elf_emachine = EM_NONE;
    elfi->elf_version = EV_NONE;

    elfi->entry_uint64 = 0;
    elfi->phoff_uint64 = 0;
    elfi->shoff_uint64 = 0;

    elfi->entry_uint32 = 0;
    elfi->phoff_uint32 = 0;
    elfi->shoff_uint32 = 0;
    
    elfi->ehsize = 0;
    elfi->phentsize = 0;
    elfi->phnum = 0;

    elfi->program_header = NULL;
    return 1;
}