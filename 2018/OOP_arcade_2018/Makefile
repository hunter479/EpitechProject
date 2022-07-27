##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##


all: core graphicals games


core:
	@make -sC ./src/core

games:
	@make -sC ./src/game

graphicals:
	@make -sC ./src/lib

clean:
	@make -sC ./src/lib clean
	@make -sC ./src/core clean
	@make -sC ./src/game clean
	@make -sC ./tests clean

fclean:	clean
	@make -sC ./src/lib fclean
	@make -sC ./src/core fclean
	@make -sC ./src/game fclean
	@make -sC ./tests fclean

re:	fclean all

tests_run: all clean
	@make -sC ./tests
	./tests/units-tests

.PHONY: all core games graphicals clean fclean re