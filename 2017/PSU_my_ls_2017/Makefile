##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	./lib/main.c\
			./lib/my_scan.c\
			./lib/stats.c\
			./lib/sort.c\
			./lib/get_stats.c\
			./lib/sorting_time.c\
			./lib/my_tools.c\
			./lib/stack.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-L./lib/my/ -lmy -Iinclude -g

NAME		=	my_ls

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -sC ./lib/my
		@gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:	fclean all
