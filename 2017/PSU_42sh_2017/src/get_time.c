/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** get_time
*/

#include "my.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

char	*delet_sec(char *my_time)
{
	char	**tab = my_str_to_wordtab(my_time, ':');
	int	size = strlen(tab[0]) + strlen(tab[1]) + 2;
	char	*to_re = malloc(sizeof(char) * size + 1);
	int	i = 0;
	int	j = 0;

	for (i = 0; tab[0][i] != '\0'; i++)
		to_re[i] = tab[0][i];
	to_re[i] = ':';
	i++;
	for (j = 0; tab[1][j] != '\0'; j++) {
		to_re[i] = tab[1][j];
		i++;
	}
	to_re[i] = '\t';
	to_re[i + 1] = '\0';
	return (to_re);
}

char	*get_char_time(char *my_time)
{
	char	**tab = my_str_to_wordtab(my_time, ' ');

	return (delet_sec(tab[3]));
}

char	*get_time(void)
{
	time_t	sec = time(NULL);
	struct tm	*my_time = localtime(&sec);
	char	*to_re = get_char_time(asctime(my_time));

	return (to_re);
}
