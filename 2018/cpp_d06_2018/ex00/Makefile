##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC_DIR		=	./src/

SRC		=	$(SRC_DIR)main.cpp \

INC		=	-I ./

OBJ		=	$(SRC:.cpp=.o)

CFLAGS		=	-Wall -Wextra -g

NAME		=	my_cat

all:			$(OBJ)
			@g++ -o $(NAME) $(OBJ) $(CFLAGS) $(INC)

clean:
			@rm -f $(OBJ)


fclean:		clean
			@rm -f $(NAME)

re:			fclean all
