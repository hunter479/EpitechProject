/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** functions to deal with post flags
*/

#include <stdarg.h>
#include <stdbool.h>
#include "my_printf.h"
#include <stdlib.h>
#include "my.h"

char	*tr_tmp(char *str, int prec, t_post_fl fl, t_flags P)
{
	char	*tmp = malloc(sizeof(char));
	int	nbr = my_getnbr(str);

	if (fl.minus == false && fl.zero == true) {
		if (nbr < 0) {
			tmp = my_strset(prec + 1, '0');
			tmp [0] = '-';
			return (tmp);
		}
		else if (nbr > 0)
			return (tmp = my_strset(prec, '0'));
	}
	if (fl.plus == true)
		if (nbr > 0)
			tmp[0] = '+';
	return (tmp);
}

char	*tr_minus(char *str, int prec, t_post_fl fl, t_flags P)
{
	char	*tmp = malloc(sizeof(char));
	int	nbr = my_getnbr(str);
	int	str_size = my_strlen(str);

	if (fl.space == true && nbr > 0) {
		str = dest_add_src(" ", str);
		prec += -1;
	}
	if (prec - str_size + 1 != 0)
		return (tmp = dest_add_src(str, my_strset(prec, ' ')));
	else
		return (tmp = dest_add_src(tmp, str));

}
char	*tr_pf(char *str, int prec, t_post_fl fl, t_flags P)
{
	char	*tmp = malloc(sizeof(char));
	int	nbr = my_getnbr(str);
	int	str_size = my_strlen(str);

	prec = (prec < 0) ? (prec * -1) - str_size : prec - str_size;
	prec = (prec < 0) ? (prec * -1) - 1 : prec - 1;
	tmp = tr_tmp(str, prec, fl, P);
	if (fl.minus == true && fl.plus == false)
		return (tmp = tr_minus(str, prec, fl, P));
	if (fl.minus == false && fl.zero == false && fl.plus == false) {
		if (prec - str_size + 1 == 0 && fl.space == false)
			return (str);
		tmp = (my_strset(prec, ' '));
	}
	if (fl.minus == false && fl.zero == true && fl.space == false) {
		if (nbr < 0)
			str++;
	}
	tmp = dest_add_src(tmp, str);
	return (tmp);
}

char	*string_per(int a, char *str)
{
	char	*tmp = malloc(sizeof(char) * my_strlen(str));
	int	b = 0;

	while (indexation(str[a], IDX) == -1) {
		tmp[b] = str[a];
		b++;
		a++;
	}
	tmp[b] = str[a];
	return (tmp);
}

int	isnum(char c)
{
	return (c >= '0' && c <= '9');
}
