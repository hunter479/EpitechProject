/*
** EPITECH PROJECT, 2018
** units-tests
** File description:
** part4
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"
#include "struct.h"
#include "my.h"
#include "nick.h"

Test(init_struct, check_val)
{
	tetri_t	*it = malloc(sizeof(tetri_t));

	init_struct(it);
	cr_assert(it->name == NULL);
	cr_assert(it->x	== -1);
	cr_assert(it->y	== -1);
	cr_assert(it->ok == -1);
	cr_assert(it->color == -1);
	cr_assert(it->form == NULL);
	cr_assert(it->next == NULL);

}
