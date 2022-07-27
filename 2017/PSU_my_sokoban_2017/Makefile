##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	main.c\
			tools.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Iinclude -Werror -Wall -g3 -lncurses

NAME		=	my_sokoban

all:		$(NAME)

$(NAME):	$(OBJ)
		@gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:	fclean all