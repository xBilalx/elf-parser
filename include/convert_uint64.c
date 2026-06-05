#include "elf.h"

unsigned long int convert_uint64(unsigned char *buf, unsigned char elf_data) {
    if (elf_data == ELFDATA2LSB)
        return (unsigned int)buf[0] |
        ((unsigned long int)buf[1] << 8) |
        ((unsigned long int)buf[2] << 16) | ((unsigned long int)buf[3] << 24) |
        ((unsigned long int)buf[4] << 32) | ((unsigned long int)buf[5] << 40)
        | ((unsigned long int)buf[6] << 48) | ((unsigned long int)buf[7] << 56);
    return ((unsigned long int)buf[0] << 56) | ((unsigned long int)buf[1] << 48) |
    ((unsigned long int)buf[2] << 40) | ((unsigned long int)buf[3] << 32) |
    (unsigned long int)(buf[4] << 24) | ((unsigned long int)buf[5] << 16) |
    ((unsigned long int)buf[6] << 8) | ((unsigned long int)buf[7]);
}
