#include "../elf_info.h"
#include <unistd.h>
#include "../convert.h"

unsigned int read_elf_u32(struct elf_info_struct *elfi)
{
    unsigned char buf[4];

    if (read(elfi->fd, buf, 4) != 4)
        return 0;
    return convert_uint32(buf, elfi->elf_data);
}