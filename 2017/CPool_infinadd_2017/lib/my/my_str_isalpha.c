/*
** EPITECH PROJECT, 2017
** my_str_isalpha.c
** File description:
** CPool_Day06_2017_Task10
*/

char	 *my_strlowcase(char *);

int	my_str_isalpha(char *str)
{
	int	is = 0;

	my_strlowcase(str);

	while (str[is] != '\0') {
		is++;
		if (str[is] == '\0')
			return (1);
	}
	return (0);
}
