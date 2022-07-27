/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** function to display %S
*/

#include <stdarg.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char	*transfer(int *u, char *str, int *a)
{
	int	k = my_strlen(str);
	char	*tmp = malloc(sizeof(char *) * k);
	char	*tmp2 = malloc(sizeof(char *) * k);

	tmp2 = my_nb_base(str[*a], "01234567");
	if (my_getnbr(tmp2) < 10)
		tmp2 = dest_add_src("\\00", tmp2);
	else
		tmp2 = dest_add_src("\\0", tmp2);
	tmp = dest_add_src(tmp, tmp2);
	*u = my_strlen(tmp2) + *a;
	free (tmp2);
	return (tmp);
}

char	*disp_ms(va_list *ap)
{
	int	a = -1;
	char	*str = my_strdup(va_arg(*ap, char *));
	int	k = my_strlen(str);
	char	*tmp = malloc(sizeof(char *) * k);
	int	u = 0;

	while (++a < k) {
		if (str[a] >= 32 && str[a] <= 127) {
			tmp[u] = str[a];
			u++;
		}
		else {
			tmp = transfer(&u, str, &a);
		}
	}
	str = my_strdup(tmp);
	free (tmp);
	return (str);
}

char	*disp_l(va_list *ap)
{
	char	*str = my_strdup(int_to_charstr(va_arg(*ap, long)));
	return (str);
}
