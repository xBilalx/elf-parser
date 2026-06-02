#include "elf.h"

unsigned short convert_uint16(unsigned char *buf, unsigned char elf_data) {
    if (elf_data == ELFDATA2LSB)
        return (uint16_t)buf[0] | (buf[1] << 8);
    return (uint16_t)(buf[0] << 8) | (buf[1]);
}
