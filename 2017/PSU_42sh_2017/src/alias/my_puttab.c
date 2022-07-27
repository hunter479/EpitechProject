/*
** EPITECH PROJECT, 2018
** kdkd
** File description:
** dkdkd
*/

int tabi(char **tab)
{
	int i = 0;

	while (tab[i] != 0) {
		puts(tab[i]);
		i = i + 1;
	}
	return (0);
}
