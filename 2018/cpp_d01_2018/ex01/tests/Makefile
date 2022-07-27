##
## EPITECH project, 2018
## my_world
## File description
## making
##

SRC_DIR		=	../

SRC		=	$(SRC_DIR)/menger.c

SRC_UT		=	./tests_check.c     \
                ./tests_menger.c    \
                ./tests_my_getnbr.c

OBJ		=	$(SRC:.c=.o)	$(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage -I..

LDFLAGS		=	-lcriterion -lgcov

NAME		=	units-tests

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@cc -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		@rm -f $(OBJ)
		@rm -f $(SRC:.c=.gcno)
		@rm -f $(SRC:.c=.gcda)
		@rm -f $(SRC_UT:.c=.gcno)
		@rm -f $(SRC_UT:.c=.gcda)

fclean	:	clean
		@rm -f ./$(NAME)

re	:	fclean all
