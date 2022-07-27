##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

AS			= nasm
ASFLAGS		= -f elf64

CC			= ld
CFLAGS		= -fPIC -shared


NAME		= libasm.so

SRC	=		./src/strcasecmp.asm	\
			./src/strpbrk.asm		\
			./src/strncmp.asm		\
			./src/strcspn.asm		\
			./src/memmove.asm		\
			./src/strlen.asm		\
			./src/strcmp.asm		\
			./src/strchr.asm		\
			./src/rindex.asm		\
			./src/memset.asm		\
			./src/memcpy.asm		\
			./src/strstr.asm		\

OBJS		= $(SRC:.asm=.o)

all: $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re