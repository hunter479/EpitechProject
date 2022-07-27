##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

tests_run:
			@make -sC ./tests
			./tests/units-tests

clean:
			@make -C ./tests clean
			@rm -f $(OBJ)


fclean:		clean
			@make -C ./tests fclean

re:			fclean all
