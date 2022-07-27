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
		$(SRC_DIR)init_struct.c		\
		$(SRC_DIR)handle_option.c	\
		$(SRC_DIR)communication.c	\
		$(SRC_DIR)str_to_wordtab.c	\
		$(SRC_DIR)mac_tools.c		\

OBJ	=	$(SRC:.c=.o)

NAME = myARPspoof

INC =	-I ./include/

CFLAGS	=	-D __USE_MISC -Wall -Wextra $(INC) -g

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
