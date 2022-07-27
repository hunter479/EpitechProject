##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## CPool_Day10_2017
##

SRC=            do-op.c

OBJ=            $(SRC:.c=.o)

LIBS=		../lib/my/libmy.a

NAME=		do-op

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) $(LIBS) 

clean:
	rm -f $(OBJ)
fclean:		clean
	rm -f $(NAME)

re: 	fclean all

# make -C ../lib/my #faire un make dans ce dossier
