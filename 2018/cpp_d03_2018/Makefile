## make
## EPITECH PROJECT, 2017
## Makefile
## File description:
## CPool_Day10_2017
##

SRC			=	./append_and_assign.c	\
				./at_clear_size.c		\
				./c_str_and_to_int.c	\
				./clear.c				\
				./compare.c				\
				./find_and_insert.c		\
				./init.c

INC			=	-iquotes

CFLAGS		+=	-Wall -Wextra $(INC)

OBJ			=	$(SRC:.c=.o)

NAME		=	libstring.a

all			:	$(NAME)

$(NAME)		:	$(OBJ)
			@ar rc $(NAME) $(OBJ)

clean:
			@rm -f $(OBJ)

fclean:			clean
			@rm -f $(NAME)

re:			fclean all
