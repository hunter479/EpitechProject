/*
** EPITECH PROJECT, 2017
** my_memset
** File description:
** parsing a character
*/

void	*my_memset(void *s, int c, int n)
{
	int	a = 0;

	while (a < n)
		((char *)s)[a++] = c;
	return (s);
}
