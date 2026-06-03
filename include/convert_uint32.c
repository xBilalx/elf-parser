#include "elf.h"

unsigned int convert_uint32(unsigned char *buf, unsigned char elf_data) {
    if (elf_data == ELFDATA2LSB)
        return (unsigned int)buf[0] |
        ((unsigned int)buf[1] << 8) |
        ((unsigned int)buf[2] << 16) | ((unsigned int)buf[3] << 24);
    return (unsigned int)(buf[0] << 24) |
    ((unsigned int)buf[1] << 16) |
    ((unsigned int)buf[2] << 8) | ((unsigned int)buf[3]);
}
