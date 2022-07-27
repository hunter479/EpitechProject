/*
** EPITECH PROJECT, 2018
** misc
** File description:
** misc
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "n4s.h"

void	get_clear(char *str)
{
	int	i = 0;
	size_t	size = 0;

	for (; str[i]; i += 1);
	for (; i > 0 && str[i] != ':'; i += -1);
	i += -1;
	for (; i > 0 && str[i] != ':'; i += -1);
	str = str + i + 1;
	if (strncmp("Track Cleared", str, 13) == 0) {
		my_putstr("CAR_FORWARD:0\n");
		getline(&str, &size, stdin);
		my_putstr("CYCLE_WAIT:3\n");
		getline(&str, &size, stdin);
		my_putstr("STOP_SIMULATION\n");
		getline(&str, &size, stdin);
		exit(0);
	}
	return;
}

void	send_cmd(char *str, int disp)
{
	char	*tmp = NULL;
	size_t	size = 0;

	my_putstr(str);
	getline(&tmp, &size, stdin);
	if (disp == 1)
		fprintf(stderr, "%s\n", tmp);
	return;
}

int	count_colons(char *str)
{
	int	count = 0;

	for (int i = 0; str[i]; i += 1) {
		if (str[i] == ':')
			count += 1;
	}
	return (count);
}

void	is_ok(char *line)
{
	int	a = 0;

	if (!line) {
		fprintf(stderr, "ERROR:\n");
		exit(84);
	}
	while (line[a] != ':' && line[a] != '\0')
		a++;
	if (line[a] == '\0')
		return;
	if (line[a + 1] == 'O' && line[a + 2] == 'K')
		return;
	else {
		fprintf(stderr, "ERROR:\n");
		exit(84);
	}
}

void	start_and_move(char *line)
{
	size_t	size = 0;

	my_putstr("START_SIMULATION\n");
	getline(&line, &size, stdin);
	is_ok(line);
	my_putstr("CAR_FORWARD:0.3\n");
	getline(&line, &size, stdin);
	my_putstr("CYCLE_WAIT:5\n");
	getline(&line, &size, stdin);
	return;
}
