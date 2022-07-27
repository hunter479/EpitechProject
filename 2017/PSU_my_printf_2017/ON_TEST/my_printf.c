/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** main function
*/

#include "my.h"
#include "my_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int	my_printf(char *str, ...)
{
	int		a = -1;
	int		ct = 0;
	t_post_fl	flags2;
	t_flags		flags;
	va_list		ap;
	char		*tmp;
	int		n_tmp = 0;
	int		prec = 0;

	va_start(ap, str);
	while (str[++a] != '\0') {
		if (str[a] == '%') {
			prec = my_getnbr(string_per(a, str));
			n_tmp = check(&a, str, &flags, &flags2);
			if (n_tmp == 0) {
				tmp = traitement(&ap, &flags);
				tmp = tr_pf(tmp, prec, flags2, flags);
				ct += my_putstr(tmp);
				free (tmp);
			}
			else
				ct += n_tmp;
		}
		else
			ct += my_putchar(str[a]);
	}
	va_end(ap);
	return (ct);
}