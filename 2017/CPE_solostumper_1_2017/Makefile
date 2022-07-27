##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	main.c\

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Iinclude -L ./lib/my -lmy

NAME		=	clean_str

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -sC ./lib/my
		@gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:	fclean all