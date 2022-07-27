/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** function to correct a str
*/

#include <unistd.h>
#include "my.h"

char	carac_list(char c)
{
	return (c != ';' && c != ' ' && c != '\t');
}

int	skip_to_word(int a, char *s, int option)
{
	if (option == 1) {
		while (s[a] == ' ' || s[a] == '\t' || s[a] == ';')
			(a)++;
		return (a);
	}
	while (s[a - 1] == ';' || s[a - 1] == '\t' || s[a - 1] == ' ') {
		if (a > 0)
			a--;
		else
			break;
	}
	return (a);
}

int	skip_space(int a, char *s)
{
	while (s[a] == ' ' || s[a] == '\t')
		(a)++;
	return (a);
}

void	is_a_char_to_take_care(int *a, int *b, char *s, char **tmp)
{
	if (s[*a] == ' ' || s[*a] == '\t')
		*a = skip_space(*a, s);
	if (s[*a] == ';') {
		(*tmp)[(*b) ++] = s[(*a) ++];
		(*tmp)[(*b) ++] = ' ';
		*a = skip_to_word(*a, s, 1);
	}
	return;
}

char	*clean_str(char *s)
{
	char	*tmp = NULL;
	int	a = 0;
	int	b = 0;

	if (!s || s[0] == '\0')
		return (NULL);
	tmp = my_malloc(tmp, my_strlen(s) + 4);
	a = skip_to_word(a, s, 1);
	while (s[a] != '\0') {
		is_a_char_to_take_care(&a, &b, s, &tmp);
		while (carac_list(s[a]) && s[a] != '\0') {
			tmp[b] = s[a];
			b ++;
			a ++;
		}
		tmp[b ++] = ' ';
	}
	b = skip_to_word(b, tmp, 2);
	tmp[b] = '\0';
	return (tmp);
}