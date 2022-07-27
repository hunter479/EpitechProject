/*
** EPITECH PROJECT, 2017
** final_stumper
** File description:
** final_stumper.c
*/

#include <unistd.h>
#include "my.h"
#define BUFF_SIZE (4096)

int	main()
{
	char	buff[BUFF_SIZE + 1];
	int	offset;
	int	len;

	offset = 0;
	while ((len = read (0, buff + offset, BUFF_SIZE - offset)) > 0) {
		offset = offset + len;
	}
	buff[offset] = '\0';
	if (len < 0 || my_error(buff) == 84) {
		my_putstr("none\n");
		return (84);
	}
	rush3(buff);
	return (1);
}