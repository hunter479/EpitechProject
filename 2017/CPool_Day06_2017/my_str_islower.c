/*
** EPITECH PROJECT, 2017
** my_str_islower.c
** File description:
** CPool_Day06_2017_Task12
*/

int     my_str_islower(char const *str)
{
        int is = 0;
        if (str[is] != '\0') {
                while (str[is] != '\0')
                {
                 	while (str[is] >= 'a' && str[is] <= 'z') {
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
