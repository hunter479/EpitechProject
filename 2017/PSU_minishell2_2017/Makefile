##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	./src/

SRC		=	$(SRC_DIR)main.c				\
			$(SRC_DIR)pipe.c				\
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

LIB		= 	-L ./lib/my -lmy

INC		=	-I ./include -I ./lib/my/include

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -g $(INC)

NAME		=	mysh

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