/*
** EPITECH PROJECT, 2017
** my_strlowcase.c
** File description:
** CPool_Day06_Task08
*/

char	 *my_strlowcase(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i = i + 1;
	}
	return (str);
}
