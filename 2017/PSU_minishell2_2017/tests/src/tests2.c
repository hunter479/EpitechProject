/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** tests2
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include "proto.h"
#include "struct.h"
#include "my.h"

Test(setenv_f_letter, check)
{
	cr_assert(first_letter('a') == 1);
	cr_assert(first_letter('/') == -1);
}

Test(setenv_letter, check)
{
	cr_assert(check_setenv("#mdr") == -1);
	cr_assert(check_setenv("Bon#jour") == -1);
	cr_assert(check_setenv("Bonjour") == 1);
}

Test(put_in_list, add)
{
	inst_t	*it = NULL;

	put_in_list("bonjour", &it);
	put_in_list("42", &it);
	put_in_list(NULL, &it);
	cr_assert(strcmp(it->str, "bonjour") == 0);
	cr_assert(strcmp(it->next->str, "42") == 0);
}

Test(tab_dup, cpy)
{
	char	**tab = NULL;
	char	**new = NULL;

	tab = NULL;
	tab = add_in_tab(tab, "test");
	tab = add_in_tab(tab, "2");
	new = my_tab_dup(tab);
	cr_assert(strcmp(new[0], "test") == 0);
	cr_assert(strcmp(new[1], "2") == 0);
}
