/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** main of the project
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include "soko.h"

void	disp_win(char **map, char *origin)
{
	int	i = -1;
	int	y = (LINES / 2) - (nbr_of_y(origin) /2);
	int	x = (COLS / 2) - (nbr_of_y(origin) / 2);

	while (1) {
		while (map[++i])
			mvprintw(y + i, x, map[i]);
		if (getch() == 27)
			break;
		refresh();
		clear();
	}
}

void	read_it(char *map)
{
	char		**final;
	WINDOW		*win;

	win = initscr();
	keypad(win, TRUE);
	curs_set(0);
	noecho();
	final = transfer_(map);
	disp_win(final, map);
	endwin();
}

int	main(int ac, char **av)
{
	char	map[BUFF + 1];
	int	fd = open(av[1], O_RDONLY);
	int	offset = 0;

	if (fd == -1)
		return (84);
	offset = read(fd, map, BUFF + 1);
	map[offset] = '\0';
	read_it(map);
	close(fd);
	return (0);
}
