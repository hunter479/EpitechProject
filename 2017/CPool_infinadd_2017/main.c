/*
** EPITECH PROJECT, 2017
** infin_add
** File description:
** main.c
*/

#include "my.h"
#include "infin_add.h"

int	w_no_minus(char *str)
{
	int	a = 0;

	while (str[0] == '-' || str[0] == '+' || str[0] == '0') {
		str++;
	}
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*calc_detect(char *str1, char *str2)
{
	int	i = my_strlen(str1) - 1;
	int	j = my_strlen(str2) - 1;
	int	m1 = 1;
	int	m2 = 1;
	char	*somme;
	int	a = 0;

	no_neg(&str1, &str2, &m1, &m2);
	somme = my_strset(str1, str2);
	a = bigger(str1, str2);
	somme = my_calc(somme, str1, str2, (m1 * m2));
	i = w_no_minus(str1);
	j = w_no_minus(str2);
	if (m1 == -1 && m2 == 1 && i == j || m1 == 1 && m2 == -1 && i == j)
		somme = somme_check(somme, str1, str2, m1);
	else
		somme = sign_to_assign(somme, m1, m2, a);
	return (somme);
}

int	main(int ac, char **av)
{
	if (error_managing(ac, av[1], av[2]) == 84)
		return (84);
	if (av[1][0] == '0' && (av[2][0] == '0')) {
		my_putstr("0");
		my_putchar('\n');
		return (0);
	}
	my_putstr(calc_detect(av[1], av[2]));
	my_putchar('\n');
	return (0);
}