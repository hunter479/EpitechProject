/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** tests
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

Test(add_in_tab, check_content)
{
	char	**tmp = NULL;

	tmp = add_in_tab(tmp, "42");
	cr_assert(strcmp(tmp[0], "42") == 0);
	tmp = add_in_tab(tmp, "bonjour");
	cr_assert(strcmp(tmp[1], "bonjour") == 0);
}

Test(nb_pipe, check_nb_pipe)
{
	cr_assert(nb_pipe("ls | | ls") == 2);
}

Test(clear_pipe, manipulation_str)
{
	char	*ref = my_strdup("ls |ls");
	char	*cleared = (clear_pipe(ref));

	cr_assert(my_strcmp(cleared, "ls | ls") != 0);
}

Test(clear_redir, manipulation_str)
{
	char	*ref = my_strdup("ls>a");
	char	*cleared = (clear_redir(ref));

	cr_assert(strcmp(cleared, "ls > a") != 0);
}

Test(clear_str, manipulation_str)
{
	char	*ref = my_strdup("ls     -l");
	char	*cleared = (clean_str(ref));

	cr_assert(strcmp(cleared, "ls -l") == 0);
}
