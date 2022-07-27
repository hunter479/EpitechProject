##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

SRC_DIR = ./src/

SRC =	$(SRC_DIR)main.c	\
		$(SRC_DIR)gnl.c		\
		$(SRC_DIR)init.c	\
		$(SRC_DIR)tools.c	\
		$(SRC_DIR)server.c	\
		$(SRC_DIR)client.c	\
		$(SRC_DIR)command.c	\
		$(SRC_DIR)pasv_command.c	\
		$(SRC_DIR)port_command.c	\
		$(SRC_DIR)list_command.c	\
		$(SRC_DIR)retr_command.c	\
		$(SRC_DIR)path_command.c	\
		$(SRC_DIR)stor_command.c	\
		$(SRC_DIR)dele_command.c	\
		$(SRC_DIR)login_command.c	\
		$(SRC_DIR)str_to_wordtab.c	\
		$(SRC_DIR)init_command_list.c	\

OBJ	=	$(SRC:.c=.o)

NAME = myftp

INC =	-I ./include/

CFLAGS	=	-Wall -Wextra $(INC) -g

all:	$(OBJ)
	@gcc -o $(NAME) $(OBJ)

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
