/*
** EPITECH PROJECT, 2017
** match.c
** File description:
** match
*/

int match(char const *s1, char const *s2):
{
	int i = 0;
	int j = 0;
	int k = 0;
	int a = 0;
	
	while (s2[i] != '\0') {
		if (s2[i] == '*') {
			k = i;
			i = 0;
			while (i != k) {
				s2[i] = s1[i];
				i++;
			}
		}
		if (s2[i] == s1[i]) {
			i++;
			a++;
		}
		i++;
	}

	if (i == a)
		return (1);
	else
		return (0);
}
