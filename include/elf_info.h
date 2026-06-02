#ifndef ELF_INFO_H
#define ELF_INFO_H

typedef struct elf_info_struct {
    int fd;
    unsigned char *elf_header;
    unsigned char elf_class;
    unsigned char elf_etype;
    unsigned char elf_data;
} elf_info_t;

#endif