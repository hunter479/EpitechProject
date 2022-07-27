##
## EPITECH PROJECT, 2018
## makefile
## File description:
## Compile everything
##

SRC_DIR		=	./src/

SRC		=	$(SRC_DIR)main.c			\
			$(SRC_DIR)term.c			\
			$(SRC_DIR)sort.c			\
			$(SRC_DIR)check.c			\
			$(SRC_DIR)put_init.c			\
			$(SRC_DIR)info_tetri.c			\
			$(SRC_DIR)tetriminos.c			\
			$(SRC_DIR)get_list_tetri.c		\
			$(SRC_DIR)tetriminos_check.c		\
			$(SRC_DIR)tools/my_free.c		\
			$(SRC_DIR)tools/my_malloc_set.c		\
			$(SRC_DIR)flag_n_arg/keys.c		\
			$(SRC_DIR)flag_n_arg/print.c		\
			$(SRC_DIR)flag_n_arg/help.c		\
			$(SRC_DIR)flag_n_arg/inits.c		\
			$(SRC_DIR)flag_n_arg/level.c		\
			$(SRC_DIR)flag_n_arg/flags.c		\
			$(SRC_DIR)flag_n_arg/map_size.c		\
			$(SRC_DIR)flag_n_arg/check_opt.c	\
			$(SRC_DIR)flag_n_arg/debug_mode.c	\
			$(SRC_DIR)flag_n_arg/key_change.c	\
			$(SRC_DIR)flag_n_arg/without_next.c


LIB		= 	-L ./lib/my -lmy

INC		=	-I ./include -I ./lib/my/include

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-w -Wall -Wextra -g $(INC)

NAME		=	tetris

all:			$(OBJ)
			@make -sC ./lib/my
			@gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS) $(INC) -lncurses

tests_run:
			@make -sC ./lib/my
			@make -sC ./tests
			./tests/units-tests

clean:
			@make -sC ./lib/my clean
			@make -sC ./tests clean
			@rm -f $(OBJ)

fclean:			clean
			@make -sC ./lib/my fclean
			@make -sC ./tests fclean
			@rm -f $(NAME)

re:			fclean all
