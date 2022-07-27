## make
## EPITECH PROJECT, 2017
## Makefile
## File description:
## CPool_Day10_2017
##

SRC =		$(shell find -path "./FILES_SRC/*" -name "*.c")

OBJ=            $(SRC:.c=.o)

NAME=		libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)

clean:
		@rm -f $(OBJ)
fclean:		clean
		@rm -f $(NAME)

re: 	fclean all
