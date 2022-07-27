##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

SRC_DIR	=	./src/

INC = -I ../../include

CXXFLAGS	=	-Wall -Wextra $(INC) -g

SRC	= 	main.cpp				\
		usage.cpp				\
		$(SRC_DIR)core.cpp				\
		$(SRC_DIR)game.cpp				\
		$(SRC_DIR)lib_concern.cpp		\
		class/dll.cpp				\
		class/parseDir.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	../../arcade

all: core

core: $(OBJ)
	@g++ -o $(NAME) $(OBJ) -ldl

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all core clean fclean re