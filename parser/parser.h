#ifndef PARSER_H
#define PARSER_H

#include "../include/elf_info.h"

int magic_elf(elf_info_t *elfi);
int class_elf(struct elf_info_struct* elfi);
int data_elf(struct elf_info_struct* elfi);
int etype_elf(struct elf_info_struct* elfi);
int etmachine_elf(struct elf_info_struct* elfi);
int version_elf(struct elf_info_struct *elfi);

// function for  64 bytes elf file 
int entry_uint64(struct elf_info_struct *elfi);

#endif