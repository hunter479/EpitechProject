##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	./

SRC		=	$(SRC_DIR)main.c \
			$(SRC_DIR)menger.c \
            $(SRC_DIR)bitmap_header.c \
            $(SRC_DIR)drawing.c

INC		=	-I ./

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -pedantic -g -std=gnu11

NAME		=	menger_face

all:		$(OBJ)
			@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(INC)

tests_run:
			@make -sC ./tests
			./tests/units-tests

clean:
			@make -C ./tests clean
			@rm -f $(OBJ)

fclean:		clean
			@make -C ./tests fclean
			@rm -f $(NAME)

re:			fclean all
