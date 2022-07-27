/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** term
*/

#include <term.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

char	*get_term(char **env)
{
	int	i = 0;

	if (!env)
		return (NULL);
	while (env[i] != NULL) {
		if (!strncmp("TERM=", env[i], 4))
			return ((char *)env[i] + 5);
		i++;
	}
	return (NULL);
}

int	init_term(char **env)
{
	char	*terminal = NULL;
	struct termios	term;

	terminal = get_term(env);
	if (!terminal) {
		write(2, "Couldn't find Term value in env\n", 31);
		return (-1);
	}
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

int	reset_term(char **env)
{
	char		*terminal = NULL;
	struct termios	term;

	terminal = get_term(env);
	if (!terminal) {
		write(2, "Couldn't find Term value in env\n", 31);
		return (-1);
	}
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}