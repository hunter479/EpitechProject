##
## EPITECH PROJECT, 2019
## make
## File description:
## make
##

SRC_NM	=	./src/nm/elf64/check64_flags.c	\
		./src/nm/elf64/get64.c		\
		./src/nm/elf64/nm64.c		\
		./src/nm/elf32/check32_flags.c	\
		./src/nm/elf32/get32.c		\
		./src/nm/elf32/nm32.c		\
		./src/nm/main.c             	\
		./src/tools/put_in_list.c	\
		./src/tools/check.c	        \
		./src//tools/check_size.c 	\
		./src/tools/elf_struct.c	\
		./src/tools/print.c		\
		./src/tools/sort.c		\
		./src/tools/get.c

SRC_OBJ =	./src/obj/obj64/obj64.c 	\
		./src/obj/obj64/print64_bis.c			\
		./src/obj/obj64/check64.c 	\
		./src/obj/obj64/print64.c			\
		./src/obj/obj64/get64.c 	\
		./src/obj/obj32/obj32.c 	\
		./src/obj/obj32/print32.c			\
		./src/obj/obj32/print32_bis.c			\
		./src/obj/obj32/get32.c 	\
		./src/obj/obj32/check32.c 	\
		./src/obj/flags.c			\
		./src/obj/main.c			\
		./src//tools/check_size.c 	\
		./src/tools/elf_struct.c 	   	\
		./src/tools/get.c			\
		./src/tools/check.c

OBJ_NM	=	$(SRC_NM:.c=.o)

OBJ_OBJDUMP	=	$(SRC_OBJ:.c=.o)

INC =	-I ./include/

CFLAGS	=	-Wall -Wextra $(INC) -g

all:  nm objdump

nm:		$(OBJ_NM)
		@gcc -o my_nm $(OBJ_NM)

objdump:	$(OBJ_OBJDUMP)
		@gcc -o my_objdump $(OBJ_OBJDUMP)

clean:
		@rm -rf $(OBJ_OBJDUMP)
		@rm -rf $(OBJ_NM)

fclean: clean
		@rm -rf my_objdump
		@rm -rf my_nm

re: fclean all

.PHONY: make re clean fclean all
