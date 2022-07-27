/*
** EPITECH PROJECT, 2017
** my_showstr
** File description:
** CPool_Day06_Task17
*/

int	my_showstr(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] <= 31 || str[i] >= 128) {
			my_putchar('\\');
			if (str[i] <= 15) {
				my_putchar('0');
			}
			my_putnbr_base(str[i], "0123456789ABCDEF");
		}
		else
			my_putchar(str[i]);
		i = i + 1;
		}
	return (0);
}
