#ifndef ELF_INFO_H
#define ELF_INFO_H

typedef struct elf_program_header {
    unsigned int p_type;
    unsigned int p_flags; // Only for 64bytes ELF files
    
    // variable for 64 bits elf files
    unsigned long int p_offset64;
    unsigned long int p_vaddr64;
    unsigned long int p_paddr64;
    unsigned long int p_filesz64;
    unsigned long int p_memsz64;
    unsigned long int p_align64;

    // variable for 32 bits elf files
    unsigned int p_offset32;
    unsigned int p_vaddr32;
    unsigned int p_paddr32;
    unsigned int p_filesz32;
    unsigned int p_memsz32;
    unsigned int p_align32;

    unsigned intp_flags; // Only for 32 bits
    struct elf_program_header *next;
} elf_program_header_t;


typedef struct elf_info_struct {
    int fd;
    unsigned char *elf_header;
    unsigned char elf_class;
    unsigned char elf_data;
    unsigned short elf_etype; // 2 bytes
    unsigned short elf_emachine; // 2 bytes
    unsigned int elf_version; // 4 bytes

    // variable for 64 BITS elf files
    unsigned long int entry_uint64;
    unsigned long int phoff_uint64;
    unsigned long int shoff_uint64;
    // variable for 32 BITS elf files
    unsigned int entry_uint32;
    unsigned int phoff_uint32;
    unsigned int shoff_uint32;

    unsigned short ehsize; // Size of ELF header
    unsigned short phentsize; // Size of Program Header table
    unsigned short phnum; // Number of Program Header
    unsigned short shentsize; // Size of Section Header table
    unsigned short shnum; // Number of Sections Header
    unsigned short shstrndx; // Index of section header who contain section names

    elf_program_header_t *program_header;
} elf_info_t;

unsigned short read_elf_u16(struct elf_info_struct *elfi);
unsigned int read_elf_u32(struct elf_info_struct *elfi);
unsigned long int read_elf_u64(struct elf_info_struct *elfi);

#endif