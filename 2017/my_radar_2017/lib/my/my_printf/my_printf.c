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
	t_type		flags;
	va_list		ap;

	my_memset(&flags, 0, sizeof(flags));
	va_start(ap, str);
	while (str[++a] != '\0') {
		if (str[a] == '%') {
			a++;
			type_detect(str[a], &flags, IDX);
			traitement(&ap, &flags);
		}
		else
			my_putchar(str[a]);
	}
	va_end(ap);
	return (0);
}