##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	./

SRC		=	$(SRC_DIR)main.c \
			$(SRC_DIR)menger.c



INC		=	-I ./

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -g

NAME		=	menger

all:			$(OBJ)
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
