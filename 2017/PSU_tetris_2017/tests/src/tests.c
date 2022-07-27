/*
** EPITECH PROJECT, 2018
** test
** File description:
** function of test
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"
#include "struct.h"
#include "my.h"
#include "nick.h"

Test(check_ret, check_arg)
{
	int	status = 0;

	status = check_arg("Bonjour", "bonjour");
	cr_assert(status == 0);
	status = check_arg("Bonjour", "Bonjour");
	cr_assert(status == 1);
	status = check_arg("Bonjour", "Bonj");
	cr_assert(status == 0);
}

Test(check_ret, check_debug_mode)
{
	char	*av[5];
	keys_t	*keys = malloc(sizeof(keys_t));

	av[1] = "-D";
	av[2] = "--debug";
	av[3] = "--debu";
	cr_assert(check_debug_mode(av, 1, keys) == 1);
	cr_assert(check_debug_mode(av, 2, keys) == 1);
	cr_assert(check_debug_mode(av, 3, keys) == 0);
}

Test(flags, check_of_return)
{
	tetri_t		*it= NULL;

	it = malloc(sizeof(*it));
	init_struct(it);
	cr_assert(flags(1, NULL, it) == 0);
	cr_assert(flags(1, NULL, NULL) == -1);
}