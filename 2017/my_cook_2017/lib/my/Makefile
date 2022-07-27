## make
## EPITECH PROJECT, 2017
## Makefile
## File description:
## CPool_Day10_2017
##

SRC_DIR		=	./src/

SRC		=	$(SRC_DIR)my_strncmp.c	\
			$(SRC_DIR)my_putstr.c	\
			$(SRC_DIR)my_strlen.c	\
			$(SRC_DIR)my_strdup.c	\
			$(SRC_DIR)my_strcpy.c


INC		=	-Iinclude

CFLAGS		=	$(INC)

OBJ		=	$(SRC:.c=.o)

NAME		=	libmy.a

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			@ar rc $(NAME) $(OBJ)

clean:
			@rm -f $(OBJ)

fclean:			clean
			@rm -f $(NAME)

re:			fclean all
