##
## EPITECH project, 2018
## my_world
## File description
## making
##

SRC_DIR		=	../src/

SRC		=	$(SRC_DIR)key_capacity/my_getstr.c		\
			$(SRC_DIR)key_capacity/write_it.c		\
			$(SRC_DIR)key_capacity/history.c		\
			$(SRC_DIR)alias/my_straliascmp.c		\
			$(SRC_DIR)key_capacity/arrow.c			\
			$(SRC_DIR)alias/alias_error.c			\
			$(SRC_DIR)status_handling.c			\
			$(SRC_DIR)isthere_another.c			\
			$(SRC_DIR)transform_right.c			\
			$(SRC_DIR)transform_pipe.c			\
			$(SRC_DIR)transform_left.c			\
			$(SRC_DIR)check_invalid.c			\
			$(SRC_DIR)space_between.c			\
			$(SRC_DIR)alias/alias.c				\
			$(SRC_DIR)spaces_tools.c			\
			$(SRC_DIR)isthere_apip.c			\
			$(SRC_DIR)the_unsetenv.c			\
			$(SRC_DIR)clear_string.c			\
			$(SRC_DIR)my_builtins.c				\
			$(SRC_DIR)the_setenv.c				\
			$(SRC_DIR)list_tools.c				\
			$(SRC_DIR)tab_tools2.c				\
			$(SRC_DIR)sethistory.c				\
			$(SRC_DIR)add_in_tab.c				\
			$(SRC_DIR)int_to_str.c				\
			$(SRC_DIR)tab_tools.c				\
			$(SRC_DIR)the_alias.c				\
			$(SRC_DIR)the_save.c				\
			$(SRC_DIR)no_multi.c				\
			$(SRC_DIR)get_time.c				\
			$(SRC_DIR)ambigous.c				\
			$(SRC_DIR)argccess.c				\
			$(SRC_DIR)redirect.c				\
			$(SRC_DIR)commands.c				\
			$(SRC_DIR)history.c				\
			$(SRC_DIR)rev_tab.c				\
			$(SRC_DIR)my_echo.c				\
			$(SRC_DIR)allfree.c				\
			$(SRC_DIR)do_exec.c				\
			$(SRC_DIR)pigrsp.c				\
			$(SRC_DIR)septab.c				\
			$(SRC_DIR)the_cd.c				\
			$(SRC_DIR)andor.c				\
			$(SRC_DIR)inits.c				\
			$(SRC_DIR)tools.c				\
			$(SRC_DIR)core.c				\
			$(SRC_DIR)exit.c				\
			$(SRC_DIR)envi.c				\
			$(SRC_DIR)term.c				\

SRC_UT		=	./tests1.c	\
			./tests2.c	\
			./tests3.c	\
			./tests4.c	\
			./tests5.c	\
			./tests6.c	\
			./tests7.c	\
			./tests8.c

LIB		=	-L ../lib/my -lmy

OBJ		=	$(SRC:.c=.o)	$(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage -I../include -I../lib/my/include

LDFLAGS		=	-lcriterion -lgcov $(LIB) -lncurses

NAME		=	units-tests

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@make -sC ../lib/my
		@cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		@rm -f $(OBJ)
		@rm -f $(SRC:.c=.gcno)
		@rm -f $(SRC:.c=.gcda)
		@rm -f $(SRC_UT:.c=.gcno)
		@rm -f $(SRC_UT:.c=.gcda)

fclean	:	clean
		@rm -f ./$(NAME)

re	:	fclean all
