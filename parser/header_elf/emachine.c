#include "header_elf.h"

#include "../include/elf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/convert.h"

const char *machine_to_string(unsigned short machine)
{
    switch (machine) {
        case EM_NONE:
            return "No machine";
        case EM_386:
            return "Intel 80386";
        case EM_X86_64:
            return "AMD x86-64";
        case EM_ARM:
            return "ARM 32-bit";
        case 183:
            return "ARM 64-bit";
        case EM_MIPS:
            return "MIPS";
        case EM_PPC:
            return "PowerPC";
        case EM_PPC64:
            return "PowerPC 64-bit";
        case EM_SPARC:
            return "SPARC";
        case EM_SPARCV9:
            return "SPARC v9 64-bit";
        case EM_IA_64:
            return "Intel IA-64";
        case 243:
            return "RISC-V";
        default:
            return "Unknown";
    }
}

int etmachine_elf(struct elf_info_struct* elfi) {

    elfi->elf_emachine = read_elf_u16(elfi);

    printf("Machine: %s (value: %u)\n",
        machine_to_string(elfi->elf_emachine),
        elfi->elf_emachine);
    return 1;
}