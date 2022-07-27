/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** printf_usage
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "proto.h"

int	display_ashe(void)
{
	int	fd = open("./assets/usage", O_RDONLY);
	int	bytes;
	char	str[11];

	if (fd == -1) {
		my_putstr("Missing usage file\n");
		return (84);
	}
	bytes = read(fd, str, 10);
	while (bytes) {
		if (bytes == -1)
			return (84);
		str[bytes] = '\0';
		my_putstr(str);
		bytes = read(fd, str, 10);
	}
	close(fd);
	return (0);
}