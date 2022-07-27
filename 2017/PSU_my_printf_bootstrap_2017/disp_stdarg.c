/*
** EPITECH PROJECT, 2017
** my_printf_bootstrap
** File description:
** sum_stdarg
*/

#include <stdarg.h>

int	disp_stdarg(char *s, ...)
{
	int	i = -1
	va_list	ap;
	while (str[++i] != '\0') {
		if (str[i] == s) {
			va_arg(ap, char*);
			my_putstr(ap);
			my_putchar('\n');
		}
		else if (str[i] == i)
			va_arg(ap, int);
			my_put_nbr(ap);
			my_putchar('\n');
		else (str[i] == c)
			va_arg(ap, char);
			my_putchar(ap);
			my_putchar('\n');
	}
	return (0);
}