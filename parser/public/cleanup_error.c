#include "../../include/elf_info.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int cleanup_error(struct elf_info_struct *elfi, const char *msg)
{
    if (msg)
        fprintf(stderr, "%s\n", msg);
    if (elfi) {
        if (elfi->fd != -1)
            close(elfi->fd);
        free(elfi->elf_header);
        free(elfi);
    }
    exit(84);
}