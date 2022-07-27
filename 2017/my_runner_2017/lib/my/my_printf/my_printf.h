/*
** EPITECH PROJECT, 2017
** my_printf.h
** File description:
** my_printf.h
*/

#ifndef MY_PRINTF_H_
	#define MY_PRINTF_H_

#define IDX "sdic"
#include <stdarg.h>

typedef	struct	s_flags
{
	char	s;
	char	d;
	char	i;
	char	c;

}		t_type;

void	*traitement(va_list *, t_type *);
void	*disp_s(va_list *);
void	*disp_d(va_list *);
void	*disp_i(va_list *);
void	*disp_c(va_list *);

#endif /* !MY_PRINTF_H_ */