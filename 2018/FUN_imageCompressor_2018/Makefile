##
## EPITECH PROJECT, 2019
## FUN_deBruijn_2018
## File description:
## Makefile
##

NAME	=	imageCompressor

all:
	stack build --copy-bins --local-bin-path .
	mv imageCompressor-exe imageCompressor

clean:
	stack clean

fclean:	clean
		rm $(NAME)

re:		clean all

.PHONY:	all clean fclean re
