/*
** EPITECH PROJECT, 2017
** my_str_isprintable.c
** File description:
** CPool_Day06_2017_Task14
*/

int     my_str_isprintable(char const *str)
{
	int     is = 0;

	if (str[is] != '\0') {
		while (str[is] != '\0') {
				while (str[is] >= 31 && str[is] <= 127) {
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
