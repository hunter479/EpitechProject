/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** copy a string on another one
*/

char	*my_strcpy(char *dest, char const *src)
{
	int	i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}