##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	main.c\
			calcule.c\
			check_and_disp.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	 -lm -Iinclude

NAME		=	104intersection

all:		$(NAME)

$(NAME):	$(OBJ)
		@gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all