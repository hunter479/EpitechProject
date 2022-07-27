##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	windows.c\
			game.c\
			event.c\
			drawing.c\
			main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Iinclude -lc_graph_prog -g -L lib/my -lmy

NAME		=	my_hunter

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -sC lib/my
		@gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:	fclean all
