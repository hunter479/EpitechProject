/*
** EPITECH PROJECT, 2017
** my_strncat.c
** File description:
** CPool_Day07_2017_Task03
*/

char	*my_strncat(char *dest, char const *src, int nb)
{
	int	i = 0;
	int	j = 0;

	while(dest[j] != '\0')
		j++;
	while(src[i] != '\0' && i < nb) {
		dest[j] = src[i];
		i++;
		j++;

	}
	dest[j] = '\0';
	return (dest);
}
