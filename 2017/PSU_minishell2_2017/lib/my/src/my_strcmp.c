/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** CPool_Day06_2017_Task05
*/

int	my_strcmp(char const *s1, char const *s2)
{
	int	i = 0;

	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s2[i] - s1[i]);
}
