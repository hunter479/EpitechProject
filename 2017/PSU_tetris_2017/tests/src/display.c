/*
** EPITECH PROJECT, 2018
** unit test
** File description:
** part for display (unit test)
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"
#include "struct.h"
#include "my.h"
#include "nick.h"

Test(display_help, check_ret_of_disp)
{
	cr_assert(display_help("./units-tests") == 0);
	cr_assert(display_help2() == 0);
	cr_assert(display_help(NULL));
}

Test(nb_tetri, check_ret_nb_tetri)
{
	int	a = 0;

	a = nb_tetri(NULL);
	cr_assert(a == 0);
}

Test(printf_arrow, check_ret_printf_arrow)
{
	cr_assert(print_arrow("bonjour") == 0);
}