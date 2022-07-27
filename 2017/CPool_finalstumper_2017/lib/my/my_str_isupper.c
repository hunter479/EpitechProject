/*
** EPITECH PROJECT, 2017
** my_str_isupper.c
** File description:
** CPool_Day06_Task13
*/

int     my_str_isupper(char const *str)
{
	int     is = 0;

	if (str[is] != '\0') {
		while (str[is] != '\0') {
                 	while (str[is] >= 'A' && str[is] <= 'Z') {
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
