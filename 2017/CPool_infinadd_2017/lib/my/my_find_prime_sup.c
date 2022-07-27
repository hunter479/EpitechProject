/*
** EPITECH PROJECT, 2017
** prime number
** File description:
** LES NOMBRES PREMIERSMIERSMIERS
*/

void	prime_num(int nb, int a, int b, int c)
{
	while (a < nb) {
		b = nb/a;
		if (nb % a == 0) {
			c = 0;
			a = nb;
		}
		else
			c = 1;
		a++;
	}
}

int	my_find_prime_sup(int nb)
{
	int	a;
	int	b;
	int	c = 0;

	while (c != 1) {
		a = 2;
		prime_num(nb, a, b, c);
		if (c == 0)
			nb = nb + 1;
	}
	return (nb);
}
