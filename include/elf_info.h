#ifndef ELF_INFO_H
#define ELF_INFO_H

typedef struct elf_info_struct {
    int fd;
    int current_index;
    unsigned char elf_class;
} elf_info_t;

#endif