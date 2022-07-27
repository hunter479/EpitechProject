/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** CPool_Day07_2017_Task02
*/

char	*my_strcat(char *dest, char const *src)
{
	int	i = 0;
	int	j = 0;

	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0') {
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
