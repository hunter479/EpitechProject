##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	./src/main.c\
			./src/tools/print_tab.c\
			./src/tools/save_var.c\
			./src/tools/my_check_setenv_cond.c\
			./src/builtins/builtins_command.c\
			./src/builtins/my_exit.c\
			./src/builtins/my_cd.c\
			./src/tools/my_clean_tools.c\
			./src/builtins/my_setenv.c\
			./src/tools/my_tabdup.c\
			./src/builtins/my_unsetenv.c\
			./src/tools/my_shell_addition.c\
			./src/my_execve.c\
			./src/tools/str_to_wordtab.c\
			./src/tools/get_next_line.c\
			./src/tools/my_sigs.c\

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Iinclude -Wall -Wextra -g

LIB		=	-L./lib/my/ -lmy

NAME		=	mysh

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -sC ./lib/my
		@gcc -o $(NAME) $(SRC) $(CFLAGS) $(LIB)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)
		@make fclean -sC ./lib/my

re:		fclean all
