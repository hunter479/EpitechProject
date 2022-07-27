/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** function to display conversion
*/

#include <stdarg.h>
#include <stdio.h>
#include "my_printf.h"
#include "my.h"

char	*disp_s(va_list *ap)
{
	char	*str = my_strdup(va_arg(*ap, char *));

	if (str == NULL)
		return ("(null)");
	else
		return (str);
}

char	*disp_d(va_list *ap)
{
	char	*str = my_strdup(int_to_charstr(va_arg(*ap, int)));
	return (str);
}

char	*disp_c(va_list *ap)
{
	char	*str = my_strdup(char_to_str((char)va_arg(*ap, int)));
	return (str);
}

char	*disp_i(va_list *ap)
{
	char	*str = my_strdup(int_to_charstr(va_arg(*ap, int)));
	return (str);
}