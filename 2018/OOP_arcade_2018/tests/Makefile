##
## EPITECH project, 2018
## my_world
## File description
## making
##


SRC_DIR		=	../src/core/

SRC		=	$(SRC_DIR)usage.cpp					\
			$(SRC_DIR)src/core.cpp				\
			$(SRC_DIR)src/game.cpp				\
			$(SRC_DIR)src/lib_concern.cpp		\
			$(SRC_DIR)class/dll.cpp				\
			$(SRC_DIR)class/parseDir.cpp		\
			../src/game/mapHandle.cpp

SRC_UT		=	./tests.cpp	\

OBJ		=	$(SRC:.cpp=.o)	$(SRC_UT:.cpp=.o)

CXXFLAGS		=	-Wall -Wextra --coverage -I ../include

LDFLAGS		=	-lcriterion -lgcov -ldl

NAME		=	units-tests

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@g++ -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		@rm -f $(OBJ)
		@rm -f $(SRC:.cpp=.gcno)
		@rm -f $(SRC:.cpp=.gcda)
		@rm -f $(SRC_UT:.cpp=.gcno)
		@rm -f $(SRC_UT:.cpp=.gcda)

fclean	:	clean
			@rm -f ./$(NAME)

re	:	fclean all

.PHONY: all clean fclean re