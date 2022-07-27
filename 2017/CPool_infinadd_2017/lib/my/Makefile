## make
## EPITECH PROJECT, 2017
## Makefile
## File description:
## CPool_Day10_2017
##

SRC	=	$(shell find -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)
		ar rc $(NAME) $(OBJ)

$(NAME):	$(OBJ)

clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)

re: 	fclean all
