##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	windows.c\
			animation1.c\
			animation2.c\
			animation3.c\
			animation4.c\
			drawing.c\
			index.c\
			main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Iinclude -lc_graph_prog -g -lm -L lib/my -lmy

NAME		=	my_screensaver

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -sC ./lib/my
		@gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:	fclean all
