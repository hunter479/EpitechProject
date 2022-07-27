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

int	type_detect(char a, void *flags, char *str)
{
	int	b = indexation(a, str);

	if (b != -1)
		((char *)flags)[b] = true;
	else
		return (-1);
	return (0);
}

void	*traitement(va_list *ap, t_type *flags)
{
	int	a = -1;
	void	*(*disp_tab[])(va_list *) = {disp_s, disp_d, disp_i,
	disp_c};

	while (IDX[++a] != '\0')
		if (((char *)flags)[a] == true)
			disp_tab[a](ap);
	my_memset(&flags, 0, sizeof(flags));
}