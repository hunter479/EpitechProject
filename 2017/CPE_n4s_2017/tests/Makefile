##
## EPITECH project, 2018
## tu
## File description
## units-tests
##

SRC	=	../src/int_to_char.c			\
		../src/my_putstr.c			\
		../src/get_value.c			\
		../src/my_revstr.c			\
		../src/misc.c				\
		../src/turn.c				\
		../src/move.c

SRC_UT	=	./src/test.c

OBJ	=	$(SRC:.c=.o) $(SRC_UT:.c=.o)

NAME	=	units-tests

CFLAGS	=	-Wall -Wextra --coverage -I../include -I../lib/my/include

LDFLAGS	=	-lcriterion -lgcov

all:		$(OBJ)
		cc -o ../$(NAME) $(OBJ) $(LIB) $(LDFLAGS)

clean:
		@rm -f $(OBJ)
		@rm -f $(SRC:.c=.gcno)
		@rm -f $(SRC_UT:.c=.gcno)
		@rm -f $(SRC:.c=.gcda)
		@rm -f $(SRC_UT:.c=.gcda)

fclean:		clean
		rm -f ../units-tests

re:		fclean all

.PHONY:		re fclean clean all
