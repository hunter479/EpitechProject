/*
** EPITECH PROJECT, 2017
** cat
** File description:
** CPool_Day12_Task01
*/

#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int	main(int ac, char *av[])
{
	int fd;
	char buffer[30];
	int size;
	int i = 1;

	mvc (ac, av);
	while (i < ac) {
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			return (1);
		else {
		size = read(fd, buffer, 30);
		write (1, buffer, size);
		}
		i++;
	}
	close (fd);
	return (0);
}

int	mvc(int ac, char **av)
{
	int fd;
	char buffer[30];
	int size;
	int i = 1;

	while (ac == 1) {
		while (size = read(0, buffer, 30 != 0))
			write(1, buffer, size);
	}
}