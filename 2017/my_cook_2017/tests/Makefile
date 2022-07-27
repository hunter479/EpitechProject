##
## EPITECH PROJECT, 2018
## Unit test
## File description:
## makefile for unit test
##

SRC_DIR		=	../src/

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
			$(SRC_DIR)check.c			\
			$(SRC_DIR)printf_usage.c

LIB		=	-L ../lib/my -lmy

SRC_UT_DIR	=	./src/

SRC_UT		=	$(SRC_UT_DIR)tests.c			\
			$(SRC_UT_DIR)tests2.c			\

OBJ		=	$(SRC:.c=.o)	$(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage -I../include

LDFLAGS		=	-lcriterion -lgcov $(LIB)

NAME		=	units-tests

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@cc -o $(NAME) $(OBJ) $(LDFLAGS) -lc_graph_prog

clean	:
		@rm -f $(OBJ)
		@rm -f $(SRC:.c=.gcno)
		@rm -f $(SRC_UT:.c=.gcno)
		@rm -f $(SRC:.c=.gcda)
		@rm -f $(SRC_UT:.c=.gcda)

fclean	:	clean
		@rm -f ./$(NAME)

re	:	fclean all
