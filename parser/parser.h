#ifndef PARSER_H
#define PARSER_H

#include "../include/elf_info.h"

int init_elf_info(elf_info_t *elfi);
void header_reader_system(struct elf_info_struct *elfi);
int cleanup_error(struct elf_info_struct *elfi, const char *msg);
void program_reader_system(struct elf_info_struct *elfi);

#endif