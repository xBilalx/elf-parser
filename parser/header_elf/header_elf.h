#ifndef HEADER_ELF_H
#define HEADER_ELF_H

#include "../include/elf_info.h"

int magic_elf(elf_info_t *elfi);
int class_elf(struct elf_info_struct* elfi);
int data_elf(struct elf_info_struct* elfi);
int etype_elf(struct elf_info_struct* elfi);
int etmachine_elf(struct elf_info_struct* elfi);
int version_elf(struct elf_info_struct *elfi);

// ----
// function for  64 bytes elf file 
int entry_uint64(struct elf_info_struct *elfi);
int phoff_uint64(struct elf_info_struct *elfi);
int shoff_uint64(struct elf_info_struct *elfi);
// function for 32 bytes elf file
int entry_uint32(struct elf_info_struct *elfi);
int phoff_uint32(struct elf_info_struct *elfi);
int shoff_uint32(struct elf_info_struct *elfi);
// ----

int get_ehsize(struct elf_info_struct* elfi);
int get_phentsize(struct elf_info_struct* elfi);
int get_phnum(struct elf_info_struct* elfi);
int get_shentsize(struct elf_info_struct* elfi);
int get_shnum(struct elf_info_struct* elfi);
int get_shstrndx(struct elf_info_struct* elfi);

#endif