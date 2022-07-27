/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** CPool_Day03_2017_Task03
*/

int	my_strlen(char const *str)
{
	int	rto;
	rto = 0;
	while (str[rto] != '\0')
		rto = rto + 1;
	return (rto);
}

char	*my_revstr(char *str)
{
	int	revlen = 0;
	int	end = my_strlen(str) - 1;
	int	c;
	int	a = 0;

	while (str[revlen] != '\0')
	{
		revlen = revlen + 1;
	}
	while (a < end)
	{
		c = str[a];
		str[a] = str[end];
		str[end] = c;
		a = a + 1;
		end = end - 1;
	}
	
	return (str);
}
