##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

SRC_DIR = ./src/

SRC =	$(SRC_DIR)main.c			\
		$(SRC_DIR)init.c			\
		$(SRC_DIR)tools.c			\
		$(SRC_DIR)sha256.c			\
		$(SRC_DIR)init_struct.c		\
		$(SRC_DIR)handle_option.c	\
		$(SRC_DIR)communication.c	\

OBJ	=	$(SRC:.c=.o)

NAME = client

INC =	-I ./include/

CFLAGS	=	-Wall -Wextra $(INC) -g

LDFLAGS = -lcrypto -lssl

all:	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	@make -sC ./tests clean
	@rm -rf $(OBJ)

fclean: clean
	@make -sC ./tests fclean
	@rm -rf $(NAME)

re: fclean all

tests_run: clean
	@make -sC ./tests
	./tests/units-tests

.PHONY: make re clean fclean all
