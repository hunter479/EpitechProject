/*
** EPITECH PROJECT, 2017
** my_putnbr_base.c
** File description:
** CPool_Day06_2017_Task15
*/

void my_putchar(char);

int	my_putnbr_base(int nbr, char const *base)
{
	int	i = 0;
	int	a = 0;
	int	len2;

	while (base[i] != '\0')
		i = i + 1;
	len2 = i;
	a = nbr % len2;
	nbr = nbr / len2;
	if (nbr != 0)
		my_putnbr_base(nbr, base);
	my_putchar(base[a]);
	return (nbr);
}
