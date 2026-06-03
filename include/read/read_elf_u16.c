#include "../elf_info.h"
#include <unistd.h>
#include "../convert.h"

unsigned short read_elf_u16(struct elf_info_struct *elfi)
{
    unsigned char buf[2];

    if (read(elfi->fd, buf, 2) != 2)
        return 0;
    return convert_uint16(buf, elfi->elf_data);
}