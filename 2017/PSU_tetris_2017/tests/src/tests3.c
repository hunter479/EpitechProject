/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** units test list 3
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"
#include "struct.h"
#include "nick.h"
#include "my.h"

Test(tetri_len_line, ret_func)
{
	cr_assert(tetri_len_line(" *") != -1);
	cr_assert(tetri_len_line(" ") != -1);
	cr_assert(tetri_len_line(NULL) == -1);
}

Test(catpath, ret_func)
{
	char	*tmp = NULL;

	tmp = catpath("A", "B");
	cr_assert(my_strcmp(tmp, "AB") == 0);
	tmp = catpath("A", NULL);
	cr_assert(tmp == NULL);
}

Test(get_info_firstline, ret_func)
{
	cr_assert(getcolor("1 2 3") == 3);
	cr_assert(getsize_x("1 2 3") == 1);
	cr_assert(getsize_y("1 2 3") == 2);
}

Test(get_name_func, ret_func)
{
	char	*tmp = NULL;

	tmp = get_name("42.tetrimino");
	cr_assert(my_strcmp(tmp, "42") == 0);
	tmp = get_name(NULL);
	cr_assert(tmp == NULL);
}