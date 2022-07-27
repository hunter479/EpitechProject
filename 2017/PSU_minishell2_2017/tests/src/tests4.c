/*
** EPITECH PROJECT, 2018
** unit test
** File description:
** part (unit test)
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

Test(tab_redir, position)
{
	char	*ref = ">";

	cr_assert(tab_redir(ref) == 1);
	cr_assert(tab_redir("bonjour") == 0);
	cr_assert(tab_redir(NULL) == -1);
}

Test(msg_redir, position)
{
	cr_assert(msg_redir(NULL, 1) == 1);
	cr_assert(msg_redir(NULL, 2) == 1);
	cr_assert(msg_redir(NULL, 3) == 1);
}
