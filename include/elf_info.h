#ifndef ELF_INFO_H
#define ELF_INFO_H


typedef struct elf_info_struct {
    int fd;
    unsigned char *elf_header;
    unsigned char elf_class;
    unsigned char elf_data;
    unsigned short elf_etype; // 2 bytes
    unsigned short elf_emachine; // 2 bytes
    unsigned int elf_version; // 4 bytes
} elf_info_t;

unsigned short read_elf_u16(struct elf_info_struct *elfi);
unsigned int read_elf_u32(struct elf_info_struct *elfi);

#endif