## make
## EPITECH PROJECT, 2017
## Makefile
## File description:
## CPool_Day10_2017
##
SRC	=	./functions/my_printf/core.c\
		./functions/my_printf/display_.c\
		./functions/my_printf/is_num.c\
		./functions/my_printf/my_put_nbr.c\
		./functions/my_printf/my_getnbr.c\
		./functions/my_printf/my_memset.c\
		./functions/my_printf/my_printf.c\
		./functions/my_printf/my_putchar.c\
		./functions/my_printf/my_putstr.c\
		./functions/my_printf/my_strcpy.c\
		./functions/my_printf/my_strdup.c\
		./functions/my_printf/my_strlen.c\
		./my_strcmp.c\
		./my_strlowcase.c\
		./int_to_char_str.c\
		./my_rev_list.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)
		@ar rc $(NAME) $(OBJ)

$(NAME):	$(OBJ)

clean:
		@rm -f $(OBJ)
fclean:		clean
		@rm -f $(NAME)

re: 	fclean all
