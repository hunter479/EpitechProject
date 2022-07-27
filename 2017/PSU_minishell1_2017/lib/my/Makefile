## make
## EPITECH PROJECT, 2017
## Makefile
## File description:
## CPool_Day10_2017
##

SRC		=	./my_strcmp.c\
			./my_strncmp.c\
			./my_printf/core.c\
			./my_printf/display_.c\
			./my_printf/is_num.c\
			./my_printf/my_getnbr.c\
			./my_printf/my_memset.c\
			./my_printf/my_printf.c\
			./my_printf/my_putchar.c\
			./my_printf/my_put_nbr.c\
			./my_printf/my_putstr.c\
			./my_printf/my_strcpy.c\
			./my_printf/my_strdup.c\
			./my_printf/my_strlen.c

OBJ		=	$(SRC:.c=.o)

NAME		=	libmy.a

all:			$(NAME)

$(NAME):		$(OBJ)
			@ar rc $(NAME) $(OBJ)

clean:
			@rm -f $(OBJ)
fclean:			clean
			@rm -f $(NAME)

re:			fclean all
