/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** clear string
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*new_string(char *str, int nb)
{
	char	*tmp = NULL;
	int	k = 0;

	tmp = malloc(sizeof(char) * (nb + 1));
	for (int i = 0; str[i] != '\0'; i ++) {
		if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'));
		else
			tmp[k++] = str[i];
	}
	tmp[k] = '\0';
	free(str);
	return (tmp);
}

char	*clear_spaces(char *str)
{
	int	nb = 0;

	for (int i = 0; str[i] != '\0'; i ++) {
		if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'));
		else
			nb += 1;
	}
	return (new_string(str, nb));
}

char	*semi_colon(char *str)
{
	char	*tmp = NULL;
	int	s = 0;
	int	i = 0;

	while ((*str == ';' || *str == ' ') && *str != '\0')
		str += 1;
	if (*str == '\0')
		return (str);
	for (s = 0; str[s] != '\0'; s ++);
	while (str[s - 1] == ';' || str[s - 1] == ' ')
		s -= 1;
	tmp = malloc(sizeof(char) * (s + 1));
	for (i = 0; i != s; i++)
		tmp[i] = str[i];
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

char	*clear_rest(char *str, int k)
{
	for (int i = 0; str[i] != '\0'; i ++)
		str[i] = (str[i] < 32 || str[i] > 126) ? ' ' : str[i];
	str = clear_spaces(str);
	if (k == 0)
		return (semi_colon(str));
	else if (k == 1)
		return (space_between(str));
	else
		return (str);
}

char	*clear_str(char *tmp, int k)
{
	char	*str = NULL;

	for (int i = 0; tmp[i] != '\0'; i ++) {
		if (tmp[i] < 0 || tmp[i] > 126) {
			my_rprintf("Command not found.\n");
			tmp[0] = '\0';
			return (tmp);
		}
	}
	while ((*tmp < 33 || *tmp > 126) && *tmp != '\0')
		tmp += 1;
	if (*tmp == '\0')
		return (my_strdup(tmp));
	else
		str = my_strdup(tmp);
	return (clear_rest(str, k));
}