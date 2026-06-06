#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "./include/elf.h"
#include "./include/elf_info.h"
#include "./parser/parser.h"

int main (int argv, char *argc[]) {
    struct elf_info_struct* elfi = NULL;
    
    elfi = malloc(sizeof(struct elf_info_struct));
    init_elf_info(elfi);
    // VERIFICATION FILE
    if (argv <= 1) {
        printf("Veuillez indiquer le nom du fichier.");
        return 84;
    }
    elfi->fd = open(argc[1], O_RDONLY);
    if (elfi->fd == -1) {
        printf("Le fichier est introuvable.");
        return 84;
    }
    header_reader_system(elfi);
    program_reader_system(elfi);
    // CLEAN PROCESS
    close(elfi->fd);
    free(elfi);
    return 0;
}
