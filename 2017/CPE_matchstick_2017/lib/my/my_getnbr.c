/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** finding number in a string
*/

int	my_getnbr(char const *str)
{
	int	i = 0;
	int	a = 0;
	int	s = 1;

	while (str[i] == '-' || str[i] == '+')
		s *= (str[i++] == '-') ? -1 : 1;
	while  (str[i] >= '0'  && str[i] <= '9')
		a = a * 10 + str[i++] - '0';
	return (a * s);
}