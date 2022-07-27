##
## EPITECH project, 2018
## my_world
## File description
## making
##

SRC_DIR		=	../src/

SRC =	$(SRC_DIR)init.c			\
		$(SRC_DIR)tools.c			\
		$(SRC_DIR)sha256.c			\
		$(SRC_DIR)init_struct.c		\
		$(SRC_DIR)handle_option.c	\
		$(SRC_DIR)communication.c	\

SRC_UT		=	./tests.c		\
				./parsing.c		\
				./check_init.c	\

INC =	-I ../include/

OBJ		=	$(SRC:.c=.o)	$(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage $(INC)

LDFLAGS		=	-lcriterion -lgcov -lcrypto -lssl

NAME		=	units-tests

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		@rm -f $(OBJ)
		@rm -f $(SRC:.c=.gcno)
		@rm -f $(SRC:.c=.gcda)
		@rm -f $(SRC_UT:.c=.gcno)
		@rm -f $(SRC_UT:.c=.gcda)

fclean	:	clean
			@rm -f ./$(NAME)

re	:	fclean all

.PHONY: all clean fclean re