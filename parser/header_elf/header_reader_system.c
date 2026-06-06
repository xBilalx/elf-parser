
#include "../../include/elf_info.h"
#include "../../include/elf.h"
#include "header_elf.h"
#include <unistd.h>
#include "../parser.h"

void header_reader_system(struct elf_info_struct *elfi) {
    unsigned int eflag;

    if (read(elfi->fd, elfi->elf_header, EI_NIDENT) != EI_NIDENT) {
        cleanup_error(elfi, "Error: [MAGIC_ELF 1] Not ELF FILE.");
    }
    // ELF FILE PARSER
    if (magic_elf(elfi) == 0)
        cleanup_error(elfi, "Error: [MAGIC_ELF 2] Not ELF FILE.");
    if (class_elf(elfi) == 0)
        cleanup_error(elfi, "Error: [CLASS_ELF] Class didn't find.");
    if (data_elf(elfi) == 0)
        cleanup_error(elfi, "Error: [TYPE_ELF] Invalid Data encoding.");
    if (etype_elf(elfi) == 0)
        cleanup_error(elfi, "Error: [TYPE_ELF] Invalid Type Value.");
    if (etmachine_elf(elfi) == 0)
        cleanup_error(elfi, "Error: [MACHINE_ELF] Invalid Machine Value.");
    if (version_elf(elfi) == 0)
        cleanup_error(elfi, "");

    if (elfi->elf_class == ELFCLASS32) {
        // 32 bytes parser
        entry_uint32(elfi);
        phoff_uint32(elfi);
        shoff_uint32(elfi);
        read(elfi->fd, &eflag, 4); // Usefull to read e_flags
    } else if (elfi->elf_class == ELFCLASS64) {
        // 64 bytes parser
        entry_uint64(elfi);
        phoff_uint64(elfi);
        shoff_uint64(elfi);
        read(elfi->fd, &eflag, 4); // Usefull to read e_flags
    }
    get_ehsize(elfi);
    get_phentsize(elfi);
    get_phnum(elfi);
    get_shentsize(elfi);
    get_shnum(elfi);
    get_shstrndx(elfi);

}