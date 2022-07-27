##
## EPITECH PROJECT, 2019
## OOP_nanotekspice_2018
## File description:
## Makefile
##

Name = deBruijn

all:
	stack build --copy-bins --local-bin-path .

clean:
	@stack clean
	@rm -rf .stack-work

fclean:	clean
	@rm -rf $(Name)

re:	fclean all
