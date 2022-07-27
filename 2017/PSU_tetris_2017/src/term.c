/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** term
*/

#include <term.h>
#include <sys/ioctl.h>
#include <unistd.h>

char	*get_term(char **env)
{
	int	i = 0;

	if (!env)
		return (NULL);
	while (env[i] != NULL) {
		if (!my_strncmp("TERM=", env[i], 4))
			return ((char *)env[i] + 5);
		i++;
	}
	return (NULL);
}

int	init_term(char **env)
{
	char			*term = get_term(env);
	static struct termios	old;
	struct termios		new;

	if (!term) {
		write(2, "Couldn't find Term value in env\n", 31);
		return (-1);
	}
	if (ioctl(0, TCGETS, &old) == -1 || ioctl(0, TCGETS, &new) == -1)
		return (-1);
	new.c_lflag &= ~ECHO;
	new.c_lflag &= ~ICANON;
	new.c_cc[VMIN] = 0;
	new.c_cc[VTIME] = 1;
	if (ioctl(0, TCSETS, &new) == -1)
		return (-1);
	return (0);
}