/*
** EPITECH PROJECT, 2017
** my_print_revalpha.c
** File description:
** CPool_Day03_2017_Task02
*/

void	my_putchar(char c);

int my_print_revalpha(void)
{
	char	z = 122;
	while (z != 96)
	{
		my_putchar(z);
		z = z - 1;
	}
	return (0);
}
