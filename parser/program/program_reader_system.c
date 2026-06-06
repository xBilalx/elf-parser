
#include "../../include/elf_info.h"
#include "../../include/elf.h"
#include <unistd.h>
#include "../parser.h"
#include <stdio.h>

void program_reader_system(struct elf_info_struct *elfi) {
    printf("Voici le nombre de programme Header :%d", elfi->phnum);
    return;
}