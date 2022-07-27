##
## EPITECH PROJECT, 2018
## makefile
## File description:
## Compile everything
##

SRC_DIR		=	./src/

SRC		=	$(SRC_DIR)init_window.c			\
			$(SRC_DIR)create_vector.c		\
			$(SRC_DIR)int_in_char.c			\
			$(SRC_DIR)concatenate.c			\
			$(SRC_DIR)same_strings.c		\
			$(SRC_DIR)string_cutter.c		\
			$(SRC_DIR)my_box.c			\
			$(SRC_DIR)list_food.c			\
			$(SRC_DIR)lists.c			\
			$(SRC_DIR)transition.c			\
			$(SRC_DIR)events.c			\
			$(SRC_DIR)init_play.c			\
			$(SRC_DIR)init_menu.c			\
			$(SRC_DIR)display_score.c		\
			$(SRC_DIR)display_order.c		\
			$(SRC_DIR)render.c			\
			$(SRC_DIR)pause.c			\
			$(SRC_DIR)check_action_play.c		\
			$(SRC_DIR)play.c			\
			$(SRC_DIR)settings.c			\
			$(SRC_DIR)check_select.c		\
			$(SRC_DIR)what_you_click.c		\
			$(SRC_DIR)game.c			\
			$(SRC_DIR)main.c			\
			$(SRC_DIR)check.c			\
			$(SRC_DIR)printf_usage.c

LIB		= 	-L ./lib/my -lmy

INC		=	-I ./include -I ./lib/my/include

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-g $(INC) -lc_graph_prog

NAME		=	my_cook

all:			$(OBJ)
			@make -sC ./lib/my
			@gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS) $(INC)

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
