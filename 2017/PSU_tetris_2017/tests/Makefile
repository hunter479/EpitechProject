##
## EPITECH PROJECT, 2018
## Unit test
## File description:
## makefile for unit test
##

SRC_DIR		=	../src/

SRC		=	$(SRC_DIR)sort.c			\
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


LIB		=	-L ../lib/my -lmy

SRC_UT_DIR	=	./src/

SRC_UT		=	$(SRC_UT_DIR)tests.c			\
			$(SRC_UT_DIR)tests2.c			\
			$(SRC_UT_DIR)tests3.c			\
			$(SRC_UT_DIR)tests4.c			\
			$(SRC_UT_DIR)display.c			\

OBJ		=	$(SRC:.c=.o)	$(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage -I../include -I../lib/my/include

LDFLAGS		=	-lcriterion -lgcov $(LIB) -lncurses

NAME		=	units-tests

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		@rm -f $(OBJ)
		@rm -f $(SRC:.c=.gcno)
		@rm -f $(SRC_UT:.c=.gcno)
		@rm -f $(SRC:.c=.gcda)
		@rm -f $(SRC_UT:.c=.gcda)

fclean	:	clean
		@rm -f ./$(NAME)

re	:	fclean all
