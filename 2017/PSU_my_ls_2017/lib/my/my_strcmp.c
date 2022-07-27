/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** CPool_Day06_2017_Task05
*/

int	my_strcmp(char const *s1, char const *s2)
{
	int s = 0;

	while (s1[s] != '\0' && s2[s] != '\0' && s1[s] == s2[s])
		s++;
	return (s2[s] - s1[s]);
}
