#include "../elf_info.h"
#include <unistd.h>
#include "../convert.h"

unsigned long int read_elf_u64(struct elf_info_struct *elfi)
{
    unsigned char buf[8];

    if (read(elfi->fd, buf, 8) != 8)
        return 0;
    return convert_uint64(buf, elfi->elf_data);
}