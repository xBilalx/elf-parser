#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "./include/elf.h"
#include "./parser/parser.h"


int main (int argv, char *argc[]) {
    struct elf_info_struct* elfi = NULL;

    // VERIFICATION FILE
    elfi = malloc(sizeof(struct elf_info_struct));
    if (argv <= 1) {
        printf("Veuillez indiquer le nom du fichier.");
        return 0;
    }
    elfi->fd = open(argc[1], O_RDONLY);
    elfi->current_index = 0;
    if (elfi->fd == -1) {
        printf("Le fichier est introuvable.");
        return 81;
    }

    // ELF FILE PARSER
    if (magic_elf(elfi) == 0) {
        fprintf(stderr, "Error: [MAGIC_ELF] Not ELF FILE.");
        close(elfi->fd);
        return 84;
    }
    class_elf(elfi);
    // CLEAN PROCESS
    close(elfi->fd);
    free(elfi);
    return 0;
}