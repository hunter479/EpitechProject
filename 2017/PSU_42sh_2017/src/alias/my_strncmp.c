/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** CPool_Day06_2017_Task06
*/

int	my_strncmp(char const *s1, char const *s2, int n)
{
	int	i = 0;
	int	nchar_i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
		if (i == n - 1)
			return (s2[i] - s1[i]);
		i++;
	}
	return (s2[i] - s1[i]);
}
