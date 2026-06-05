CC	=	gcc

NAME	=	elf_parser

SRC	=	main.c \
		parser/header_elf/magic.c \
		parser/header_elf/class.c \
		parser/header_elf/data.c \
		parser/header_elf/etype.c \
		parser/header_elf/emachine.c \
		parser/header_elf/version.c \
		parser/header_elf/64bytes/entry_uint64.c \
		parser/header_elf/32bytes/entry_32.c \
		include/convert_uint16.c \
		include/convert_uint32.c \
		include/convert_uint64.c \
		include/read/read_elf_u16.c \
		include/read/read_elf_u32.c \
		include/read/read_elf_u64.c \
		parser/header_elf/64bytes/phoff_64.c \
		parser/header_elf/32bytes/phoff_32.c \
		parser/header_elf/64bytes/shoff_64.c \
		parser/header_elf/32bytes/shoff_32.c \
		parser/header_elf/get_ehsize.c \
		parser/header_elf/get_phentsize.c \
		parser/header_elf/get_phnum.c \
		parser/header_elf/get_shentsize.c	\
		parser/header_elf/get_shnum.c	\
		parser/header_elf/get_shstrndx.c	\


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

clear:	clean

allclear:	fclean

.PHONY: all clean fclean re clear allclear