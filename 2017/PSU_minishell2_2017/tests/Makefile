##
## EPITECH PROJECT, 2018
## Unit test
## File description:
## makefile for unit test
##

SRC_DIR		=	../src/

SRC		=	$(SRC_DIR)pipe.c				\
			$(SRC_DIR)get_cmd.c				\
			$(SRC_DIR)save_var.c				\
			$(SRC_DIR)core_shell.c				\
			$(SRC_DIR)prep_redir.c				\
			$(SRC_DIR)check_tab_validity.c			\
			$(SRC_DIR)check_tab_validity2.c			\
			$(SRC_DIR)execve/my_execve.c			\
			$(SRC_DIR)execve/prep_exec.c			\
			$(SRC_DIR)execve/error_execve.c			\
			$(SRC_DIR)tools/my_sigs.c			\
			$(SRC_DIR)tools/my_tabdup.c			\
			$(SRC_DIR)tools/clear_str.c			\
			$(SRC_DIR)tools/print_tab.c			\
			$(SRC_DIR)tools/add_in_tab.c			\
			$(SRC_DIR)tools/clear_pipe.c			\
			$(SRC_DIR)tools/clear_redir.c			\
			$(SRC_DIR)tools/concate_tab.c			\
			$(SRC_DIR)tools/my_clean_tools.c		\
			$(SRC_DIR)tools/str_to_wordtab.c		\
			$(SRC_DIR)tools/my_shell_addition.c		\
			$(SRC_DIR)tools/prep_instruct_list.c		\
			$(SRC_DIR)tools/my_check_setenv_cond.c		\
			$(SRC_DIR)tools/prep_instruct_tab_list.c	\
			$(SRC_DIR)builtins/builtins_command.c		\
			$(SRC_DIR)builtins/my_exit.c			\
			$(SRC_DIR)builtins/my_setenv.c			\
			$(SRC_DIR)builtins/my_cd.c			\
			$(SRC_DIR)builtins/my_unsetenv.c


LIB		=	-L ../lib/my -lmy

SRC_UT_DIR	=	./src/

SRC_UT		=	$(SRC_UT_DIR)tests.c			\
			$(SRC_UT_DIR)tests2.c			\
			$(SRC_UT_DIR)tests3.c			\
			$(SRC_UT_DIR)tests4.c			\

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
		@rm -f $(SRC_UT:.c=.gcno)
		@rm -f $(SRC:.c=.gcda)
		@rm -f $(SRC_UT:.c=.gcda)

fclean	:	clean
		@rm -f ./$(NAME)

re	:	fclean all
