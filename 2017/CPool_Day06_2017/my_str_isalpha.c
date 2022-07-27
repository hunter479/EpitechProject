/*
** EPITECH PROJECT, 2017
** my_str_isalpha.c
** File description:
** CPool_Day06_2017_Task10
*/

int	my_str_isalpha(char const *str)
{
	int	i = 0;
	if (str[i] != '\0') {
		while (str[i] != '\0')
		{
			while (str[i] >= 'a' && str[i] <= 'z'|| str[i] >= 'A' && str[i] <= 'Z') {
				i++;
				if (str[i] == '\0')
					return (1);
			}
			return (0);
		}
	}
	else
		return (1);
	
}
