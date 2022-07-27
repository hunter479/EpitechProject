/*
** EPITECH PROJECT, 2017
** tools for the printf
** File description:
** fonction principal for the printf
*/

#include <stdarg.h>
#include <stdbool.h>
#include "my_printf.h"
#include <stdlib.h>
#include "my.h"

int	indexation(char c, char *str)
{
	int	a = 0;

	while (str[a] != '\0' && str[a] != c)
		a++;
	return (str[a] ? a : -1);
}

int	ty_dt(char a, void *flags, char *str)
{
	int	b = indexation(a, str);

	if (b != -1)
		((char *)flags)[b] = true;
	else
		return (-1);
	return (0);
}

char	*traitement(va_list *ap, t_flags *flags)
{
	int	a = -1;
	char	*to_add;

	while (IDX[++a] != '\0') {
		if (((char *)flags)[a] == true)
			to_add = (disp_tab[a](ap));
	}
	return (to_add);
}

int	check(int *a, char *s, t_flags *flags, t_post_fl *flags2)
{
	char	*st = string_per(*a, s);
	int	check1 = 0;
	int	check2 = 0;

	(*a)++;
	my_memset(flags, 0, sizeof(*flags));
	my_memset(flags2, 0, sizeof(*flags2));
	while (indexation(s[*a], IDX) == -1) {
		if ((ty_dt(s[*a], flags2, POST_FL) == -1) && !(isnum(s[*a])))
			check1 = -1;
		(*a)++;
	}
	check2 = ty_dt(s[*a], flags, IDX);
	if (check2 == -1 || check1 == -1) {
		my_putstr(st);
		return (my_strlen(st));
	}
	return (0);
}