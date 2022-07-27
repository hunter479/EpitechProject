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

void	*disp_s(va_list *ap)
{
	char	*str = va_arg(*ap, char *);

	if (str == NULL)
		return ("(null)");
	else
		my_putstr(str);
}

void	*disp_d(va_list *ap)
{
	int	i = my_put_nbr(va_arg(*ap, int));
}

void	*disp_c(va_list *ap)
{
	char	str = (char)va_arg(*ap, int);
	my_putchar(str);
}

void	*disp_i(va_list *ap)
{
	int	i = my_put_nbr(va_arg(*ap, int));
}