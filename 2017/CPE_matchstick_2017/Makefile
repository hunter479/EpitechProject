##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	./src/main.c\
			./src/verification.c\
			./src/my_ia.c\
			./src/cleaning.c\
			./src/get_next_line.c\
			./src/match_and_line.c\
			./src/core_of_the_game.c\
			./src/do_my_square.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Iinclude -g

LIB		=	 -L./lib/my/ -lmy

NAME		=	matchstick

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -sC ./lib/my
		@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all
