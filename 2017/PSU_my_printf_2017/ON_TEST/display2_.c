/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** display conversion -
*/

#include <stdarg.h>
#include <stdio.h>
#include "my_printf.h"
#include "my.h"

char	*disp_o(va_list *ap)
{
	char	*s = my_strdup(my_nb_base(va_arg(*ap, unsigned int), OCT));
	return (s);
}

char	*disp_u(va_list *ap)
{
	char	*s = my_strdup(my_nb_base(va_arg(*ap, unsigned int), DECI));
	return (s);
}

char	*disp_x(va_list *ap)
{
	char	*s = my_strdup(my_nb_base(va_arg(*ap, unsigned int), Hm));
	return (s);
}

char	*disp_mx(va_list *ap)
{
	char	*s = my_strdup(my_nb_base(va_arg(*ap, unsigned int), HM));
	return (s);
}

char	*disp_b(va_list *ap)
{
	char	*str = my_strdup(my_nb_base(va_arg(*ap, unsigned int), B));
	return (str);
}
