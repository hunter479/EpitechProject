/*
** EPITECH PROJECT, 2017
** my_str_isalpha.c
** File description:
** CPool_Day06_2017_Task10
*/

int	my_str_isalpha(char const *str)
{
	int	is = 0;
	if (str[is] != '\0') {
		while (str[is] != '\0') {
			while (str[is] >= 'a' && str[is] <= 'z'|| str[is] >= 'A' && str[is] <= 'Z') {
				is++;
				if (str[is] == '\0')
					return (1);
			}
			return (0);
		}
	}
	else
		return (1);
}
