/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** reverse
*/

char	*my_revstr(char *str)
{
	char temp;
	int a = 0;
	int b = 0;

	while (str[b] != '\0')
		b = b +1;
	b = b - 1;
	while (a < b) {
		temp = str[a];
		str[a] = str[b];
		str[b] = temp;
		a = a + 1;
		b = b - 1;
	}
	return (str);
}
