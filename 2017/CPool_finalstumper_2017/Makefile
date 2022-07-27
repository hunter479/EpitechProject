##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC=		$(shell find -maxdepth 1 -name "*.c")

OBJ=            $(SRC:.c=.o)

CFLAGS=		-L./lib/my/ -lmy -Iinclude

NAME=		rush3

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)
fclean:		clean
	rm -f $(NAME)

re: 	fclean all

# make -C ../lib/my #faire un make dans ce dossier