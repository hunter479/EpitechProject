##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	main.c\
			set.c\
			tools.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Iinclude -lc_graph_prog -g -L ./lib/my -lmy

NAME		=	my_radar

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -sC ./lib/my
		@gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:	fclean all