/*
** EPITECH PROJECT, 2018
** CPE_n4s_2017
** File description:
** turn
*/

#include "n4s.h"
#include <unistd.h>
#include <criterion/criterion.h>

Test(nbrlen, check_return)
{
	int	a = 0;

	a = nbrlen(10);
	cr_assert(a == 2);
	a = nbrlen(0);
	cr_assert(a == 1);
}

Test(int_to_char, check_return)
{
	char *tmp = NULL;

	tmp = int_to_char(40);
	cr_assert(strcmp(tmp, "40") == 0);
}