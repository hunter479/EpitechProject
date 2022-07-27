##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

INC = -I ../../include/ -I ../../include/classLib

CXXFLAGS	=	-fpic -Wall -Wextra $(INC) -g

############################# Ncurses ############################

SRC_ncurses	= 	ncurses/init.cpp		\
				ncurses/get_name.cpp	\
				ncurses/printTitle.cpp	\
				ncurses/draw.cpp	\
				ncurses/input.cpp	\

OBJ_ncurses	=	$(SRC_ncurses:.cpp=.o)

NAME_ncurses	=	../../lib/lib_arcade_ncurses.so

############################# Sfml ##############################

SRC_sfml	=	sfml/init.cpp			\
				sfml/get_name.cpp		\
				sfml/draw.cpp

OBJ_sfml	=	$(SRC_sfml:.cpp=.o)

NAME_sfml	=	../../lib/lib_arcade_sfml.so

############################# Rules #############################

all:	lib

lib:	libncurses libsfml

libncurses: $(OBJ_ncurses)
	@g++ -shared -o $(NAME_ncurses) $(OBJ_ncurses) -lncurses

libsfml: $(OBJ_sfml)
	@g++ -shared -o $(NAME_sfml) $(OBJ_sfml) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	@rm -f $(OBJ_sfml)
	@rm -f $(OBJ_ncurses)

fclean:	clean
	@rm -f $(NAME_sfml)
	@rm -f $(NAME_ncurses)

re:	fclean all

.PHONY: all lib libncurses libsfml clean fclean re