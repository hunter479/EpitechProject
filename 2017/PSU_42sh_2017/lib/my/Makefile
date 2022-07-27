##int	isnum(char);
## EPITECH PROJECT, 2017
## make
## File description:
## make
##

PRINTF_DIR	=	my_printf/

SRC_DIR		=	./src/

SRC		=	$(SRC_DIR)get_map.c			\
			$(SRC_DIR)my_strcmp.c			\
			$(SRC_DIR)my_strcat.c			\
			$(SRC_DIR)my_strncmp.c			\
			$(SRC_DIR)my_strcatenv.c		\
			$(SRC_DIR)get_next_line.c		\
			$(SRC_DIR)my_strcmppath.c		\
			$(SRC_DIR)my_str_to_wordtab.c		\
			$(SRC_DIR)$(PRINTF_DIR)core.c		\
			$(SRC_DIR)$(PRINTF_DIR)display_.c	\
			$(SRC_DIR)$(PRINTF_DIR)my_getnbr.c	\
			$(SRC_DIR)$(PRINTF_DIR)my_memset.c	\
			$(SRC_DIR)$(PRINTF_DIR)my_printf.c	\
			$(SRC_DIR)$(PRINTF_DIR)my_putstr.c	\
			$(SRC_DIR)$(PRINTF_DIR)my_strcpy.c	\
			$(SRC_DIR)$(PRINTF_DIR)my_strlen.c	\
			$(SRC_DIR)$(PRINTF_DIR)my_strdup.c	\
			$(SRC_DIR)$(PRINTF_DIR)my_putchar.c	\
			$(SRC_DIR)$(PRINTF_DIR)my_put_nbr.c	\
			$(SRC_DIR)$(PRINTF_DIR)isalphanum.c	\
			$(SRC_DIR)$(PRINTF_DIR)my_printerror.c

INC		=	-I./include

CFLAGS		+=	-g $(INC)

OBJ		=	$(SRC:.c=.o)

NAME		=	libmy.a

all: 			$(NAME)

$(NAME)		: 	$(OBJ)
			@ar rc $(NAME) $(OBJ)

clean		:
			@rm -f $(OBJ)

fclean		:	clean
			@rm -f $(NAME)

re		:	clean fclean all
