CC	=	gcc

NAME	=	elf_parser

SRC	=	main.c \
		parser/magic.c \
		parser/class.c \
		parser/data.c \
		parser/etype.c \
		parser/emachine.c \
		parser/version.c \
		parser/64bytes/entry_uint64.c \
		include/convert_uint16.c \
		include/convert_uint32.c \
		include/convert_uint64.c \
		include/read/read_elf_u16.c \
		include/read/read_elf_u32.c \
		include/read/read_elf_u64.c

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