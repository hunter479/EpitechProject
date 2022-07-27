##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

INC = -I ../../include/ -I ../../include/classGame

CXXFLAGS	=	-fpic -Wall -Wextra $(INC) -g

############################# nibbler ############################

SRC_nibbler	= 	nibbler/init.cpp		\
				nibbler/input.cpp		\
				nibbler/game.cpp		\
				mapHandle.cpp		\

OBJ_nibbler	=	$(SRC_nibbler:.cpp=.o)

NAME_nibbler	=	../../games/lib_arcade_nibbler.so

############################# nibbler ############################

SRC_pacman	= 	pacman/init.cpp		\
				pacman/input.cpp		\
				pacman/game.cpp		\
				mapHandle.cpp		\

OBJ_pacman	=	$(SRC_pacman:.cpp=.o)

NAME_pacman	=	../../games/lib_arcade_pacman.so

############################# Rules #############################

all:	lib

lib:	libnibbler libpacman

libnibbler: $(OBJ_nibbler)
	@g++ -shared -o $(NAME_nibbler) $(OBJ_nibbler)


libpacman: $(OBJ_pacman)
	@g++ -shared -o $(NAME_pacman) $(OBJ_pacman)

clean:
	@rm -f $(OBJ_nibbler)
	@rm -f $(OBJ_pacman)

fclean:	clean
	@rm -f $(NAME_nibbler)
	@rm -f $(NAME_pacman)

re:	fclean all

.PHONY: all lib libnibbler libpacman clean fclean re