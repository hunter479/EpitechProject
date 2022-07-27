/*
** EPITECH PROJECT, 2017
** my_strstr.c
** File description:
** CPool_Day06_Task04
*/

char	*my_strstr(char const *str, char *to_find)
{
	int	to_loop = 0;
	int	to_find_loop = 0;
	int	strstr_loop = 0;

	while (to_find[to_loop] != '\0')
		to_loop++;
	while (str[strstr_loop] != '\0') {
		if (str[strstr_loop] == to_find[0]) {
			to_find_loop = 0;
			while (to_find[to_find_loop++] == str[strstr_loop++]) {
				if (to_loop == to_find_loop)
					return (to_find);
			}
		}
		strstr_loop++;
	}
	return (0);
}
