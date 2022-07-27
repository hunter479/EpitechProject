/*
** EPITECH PROJECT, 2017
** bootstrap_my_printf
** File description:
** sum_stdarg.c
*/

#include <stdarg.h>

int	sum_stdarg(int i, int nb, ...)
{
	int	a = 0;
	int	b = 0;
	va_list	 ap;
	va_start(ap, nb);
	if i = 0 {
		while(a++ < nb)
			b += va_arg(ap, int);
	}
	if i = 1 {
		while (a++ < nb)
			b = my_strlen(va_arg(ap, char *)):
	}
	va_end(ap);
	return (b);
}