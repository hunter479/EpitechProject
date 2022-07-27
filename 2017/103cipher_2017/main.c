/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** main.c
*/

int	is_num(char *str)
{
	int	i = 0;

	while (str[i]) {
		if (str[i] == '0' || str['0'] == '1')
			return (0);
		else
			return (-1);
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (84);
	if (is_num(av[3]) == -1)
		return (84);
}