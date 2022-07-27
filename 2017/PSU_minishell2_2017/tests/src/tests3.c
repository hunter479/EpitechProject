/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** tests3
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

Test(inst_len, lengh)
{
	char	*ref = NULL;

	ref = my_strdup("ls ; ls");
	cr_assert(inst_len(ref) == 3);
}

Test(nb_instruct, lengh)
{
	char	*ref = NULL;

	ref = my_strdup("ls ; ls");
	cr_assert(nb_instruct(ref) == 3);
}

Test(str_tab_list, cut)
{
	char	*str = NULL;
	char	**tmp = NULL;

	str = my_strdup("ls ; 42");
	tmp = str_to_tab_list(str);
	cr_assert(strcmp(tmp[0], "ls") == 0);
	cr_assert(strcmp(tmp[1], "42") == 0);
}

Test(nb_word, count)
{
	char	*ref = "ls ls";

	cr_assert(nbr_word(ref) == 3);
}
