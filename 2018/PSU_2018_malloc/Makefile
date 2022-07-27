##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

SRC	=	./src/malloc.c	\
		./src/realloc.c	\
		./src/free.c

OBJ	=	$(SRC:.c=.o)

INC =	-I ./include/

CFLAGS	=	-fpic -Wall -Wextra $(INC)

NAME	=	libmy_malloc.so

all:	$(OBJ)
	gcc -shared -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: make re clean fclean all