##
## EPITECH PROJECT, 2019
## OOP_nanotekspice_2018
## File description:
## Makefile
##

NAME = funEvalExpr

all:
	stack build --copy-bins --local-bin-path .
	mv evalexpr-exe $(NAME)

clean:
	@stack clean
	@rm -rf .stack-work
	@rm -rf stack.yaml.lock

fclean:	clean
	@rm -rf $(NAME)

re:	fclean all
