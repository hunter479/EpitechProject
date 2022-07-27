##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

SRC	=	./src/int_to_char.c			\
		./src/my_putstr.c			\
		./src/get_value.c			\
		./src/my_revstr.c			\
		./src/misc.c				\
		./src/turn.c				\
		./src/move.c				\
		./src/main.c

OBJ	=	$(SRC:.c=.o)

INC	=	-I ./include

CFLAGS	=	-g -Wextra -Wall $(INC) $(LIB)

NAME	=	ai

all:
	@make project

project:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(INC) -lm

clean:
	rm -f $(OBJ)
	@rm -f ./tests/*.gcn
	@rm -f ./tests/*.gcov
	@rm -f ./tests/*.gcda
	@rm -f ./tests/*.*o
	@rm -f ./src/*.gcno
	@rm -f ./src/*.gcov
	@rm -f ./src/*.gcda

fclean:	clean
	rm -f $(NAME)
	make -sC ./tests fclean

re:	clean fclean all

tests_run:
		make -sC ./tests
		./units-tests

.PHONY:	make re clean fclean all
