/*
** EPITECH PROJECT, 2017
** concat_params.c
** File description:
** CPool_Day08_2017_Task02
*/

#include <unistd.h>
#include <stdlib.h>

char	*boucle_concat(int argc, char **argv)
{
	int k = 1;
	int i;
	char *str;
	
	while (i < argc) {
		k += my_strlen(argv[i]) + 1;
		i++;
	}
	str = malloc(sizeof(char) * k);
	if (str == NULL)
		return (NULL);
	return (str);
}

char   *concat_params(int argc, char **argv)
{
        int i = 0;
        char *str;
        int k;

        str = boucle_concat(argc, argv);
        i = 0;
        k = 0;
        while (i < argc) {
                my_strcpy(str + k, argv[i]);
                k += my_strlen(argv[i]);
                str[k++] = '\n';
                i++;
        }
        str[k] = '\0';
        return (str);
}
