/*
** EPITECH PROJECT, 2017
** my_prinftf.h
** File description:
** protype & define
*/

#ifndef MY_PRINTF_H_
	#define MY_PRINTF_H_

#define IDX "sdicouxXbSl"
#define POST_FL "#0- +"
#define B "01"
#define OCT "01234567"
#define DECI "0123456789"
#define HM "0123456789ABCDEF"
#define Hm "0123456789abcdef"
#include <stdarg.h>
typedef	struct	s_flags
{
	char	s;
	char	d;
	char	i;
	char	c;
	char	o;
	char	u;
	char	x;
	char	mx;
	char	b;
	char	ms;
	char	l;
}	t_flags;

typedef struct	s_post_fl
{
	char	diez;
	char	zero;
	char	minus;
	char	space;
	char	plus;
}	t_post_fl;

int	check(int *a, char *str, t_flags *, t_post_fl *);
char	*tr_tmp(char *, int, t_post_fl, t_flags);
char	*tr_pf(char *, int, t_post_fl, t_flags);
char	*traitement(va_list *, t_flags *);
char	*disp_s(va_list *);
char	*disp_d(va_list *);
char	*disp_i(va_list *);
char	*disp_c(va_list *);
char	*disp_o(va_list *);
char	*disp_u(va_list *);
char	*disp_x(va_list *);
char	*disp_mx(va_list *);
char	*disp_b(va_list *);
char	*disp_ms(va_list *);
char	*disp_l(va_list *);
static char*	(*disp_tab[])(va_list *) = {disp_s, disp_d, disp_i, disp_c,
disp_o, disp_u, disp_x, disp_mx, disp_b, disp_ms, disp_l};

#endif /* !MY_PRINTF_H_ */
