/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** test list 2
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"
#include "struct.h"
#include "nick.h"
#include "my.h"

Test(init_flags, check_return_of_struct_fl)
{
	fl_t	*fl = NULL;

	fl = init_flags(fl);

	cr_assert(fl[17].cmp == NULL);
}

Test(init_keys, check_value_keys)
{
	keys_t	*keys = malloc(sizeof(keys_t));

	init_keys(keys);
	cr_assert(keys->level == 1);
	cr_assert(my_strcmp("q", keys->quit) == 0);
	cr_assert(my_strcmp(" ", keys->pause) == 0);
	cr_assert(keys->row == 20);
	cr_assert(keys->col == 10);
	cr_assert(keys->next == 1);
	cr_assert(keys->debug == 0);
}

Test(check_line_form, ret_of_func)
{
	cr_assert(check_line_form(" * *") == 0);
	cr_assert(check_line_form(" D* *") == -1);
	cr_assert(check_line_form(NULL) == -1);
}

Test(Check_first_line, ret_func)
{
	cr_assert(check_first_line("1 1 1") == 0);
	cr_assert(check_first_line("1 1") == -1);
	cr_assert(check_first_line("1 1 1 1") == -1);
	cr_assert(check_first_line("1 D 1") == -1);
	cr_assert(check_first_line("1 1 1 blabla") == -1);
	cr_assert(check_first_line(NULL) == -1);
}

Test(Check_tetri, ret_func)
{
	cr_assert(check_tetri("bonj.tetri") == -1);
	cr_assert(check_tetri(".bonj.tetrimino") == -1);
	cr_assert(check_tetri("bonj.c") == -1);
	cr_assert(check_tetri(".tetrimino") == -1);
	cr_assert(check_tetri(NULL) == -1);
	cr_assert(check_tetri("bonj.tetrimino") == 0);
}
