##
## EPITECH project, 2018
## my_world
## File description
## making
##

SRC_DIR		=	../src/

SRC =	$(SRC_DIR)gnl.c		\
		$(SRC_DIR)init.c	\
		$(SRC_DIR)tools.c	\
		$(SRC_DIR)server.c	\
		$(SRC_DIR)client.c	\
		$(SRC_DIR)command.c	\
		$(SRC_DIR)pasv_command.c	\
		$(SRC_DIR)port_command.c	\
		$(SRC_DIR)list_command.c	\
		$(SRC_DIR)retr_command.c	\
		$(SRC_DIR)path_command.c	\
		$(SRC_DIR)stor_command.c	\
		$(SRC_DIR)dele_command.c	\
		$(SRC_DIR)login_command.c	\
		$(SRC_DIR)str_to_wordtab.c	\
		$(SRC_DIR)init_command_list.c	\

SRC_UT		=	./tests.c	\
				./init.c	\
				./list.c	\
				./login.c	\
				./login2.c	\
				./path.c	\
				./serv.c	\
				./transfer.c	\

INC =	-I ../include/

OBJ		=	$(SRC:.c=.o)	$(SRC_UT:.c=.o)

CFLAGS		=	-Wall -Wextra --coverage $(INC)

LDFLAGS		=	-lcriterion -lgcov

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