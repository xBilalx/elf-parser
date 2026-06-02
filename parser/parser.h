#ifndef PARSER_H
#define PARSER_H

#include "../include/elf_info.h"

int magic_elf(elf_info_t *elfi);
int class_elf(struct elf_info_struct* elfi);
int data_elf(struct elf_info_struct* elfi);
int etype_elf(struct elf_info_struct* elfi);

#endif