##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	$(shell find -path "./src/*" -name "*.c")

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-L./lib/my/ -lmy -Iinclude -W -Werror -Wall --coverage

NAME		=	push_swap

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -sC ./lib/my
		@gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all