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

    // variable for 64 bytes elf files
    unsigned long int entry_uint64;
    unsigned long int phoff_uint64;
    unsigned long int shoff_uint64;
    // variable for 32 bytes elf files
    unsigned int entry_uint32;
    unsigned int phoff_uint32;
    unsigned int shoff_uint32;

    unsigned short ehsize; // Size of ELF header
    unsigned short phentsize; // Size of Program Header table
    unsigned short phnum; // Number of Program Header
    unsigned short shentsize; // Size of Section Header table
    unsigned short shnum; // Number of Sections Header
    unsigned short shstrndx; // Index of section header who contain section names

} elf_info_t;

unsigned short read_elf_u16(struct elf_info_struct *elfi);
unsigned int read_elf_u32(struct elf_info_struct *elfi);
unsigned long int read_elf_u64(struct elf_info_struct *elfi);

#endif