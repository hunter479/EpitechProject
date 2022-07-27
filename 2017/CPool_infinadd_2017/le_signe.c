/*
** EPITECH PROJECT, 2017
** infin_add
** File description:
** le_signe
*/

#include "infin_add.h"

char	*sign_check(char *somme, int A1, int A2)
{
	if (A1 == 1 && A2 == 1)
		somme++;
	if (A1 == -1 && A2 == -1)
		somme[0] = '-';
	return (somme);
}

char	*sign_check2(char *somme, int A1, int A2, int a)
{
	if (a == 0)
		somme++;
	if (a == 1)
		somme[0] = '-';
	return (somme);
}

char	*sign_check3(char *somme, int A1, int A2, int a)
{
	if (a == 0)
		somme[0] = '-';
	if (a == 1)
		somme++;
	return (somme);
}

char	*sign_to_assign(char *somme, int A1, int A2, int a)
{
	while (somme[1] == '0')
		somme++;
	if (A1 == -1 && A2 == 1)
		somme = sign_check2(somme, A1, A2, a);
	else if (A1 == 1 && A2 == -1)
		somme = sign_check3(somme, A1, A2, a);
	else
		somme = sign_check(somme, A1, A2);
	return (somme);
}