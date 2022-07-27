/*
** EPITECH PROJECT, 2017
** my_str_isnum.c
** File description:
** CPool_Day06_2017_Task11
*/

int     my_str_isnum(char const *str)
{
	int     is = 0;

        if (str[is] != '\0') {
		while (str[is] != '\0') {
                 	while (str[is] >= '0' && str[is] <= '9') {
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
