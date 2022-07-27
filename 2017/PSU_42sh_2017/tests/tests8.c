/*
** EPITECH PROJECT, 2018
** lem_in
** File description:
** units tests
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include "my.h"

Test(check, do_exec)
{
	char	*builtin[6] = {"cd", "exit", "env", "setenv", "unsetenv", NULL};
	bt_t	*bt = NULL;
	char	**env;
	mysh_t	ms;

	env = my_str_to_wordtab("ceci est un env", ' ');
	bt = init_values(&ms, env, bt);
	ms.exe = strdup("/bin/ls");
	ms.arg = my_str_to_wordtab("cd src", ' ');
	ms.env = tab_dup(env, 0);
	do_exec(&ms, bt, 0);
	cr_assert(ms.ret == 0);
	ms.exe = strdup("/bin/laezs");
	ms.arg = my_str_to_wordtab("laezs src", ' ');
	do_exec(&ms, bt, 0);
	cr_assert(ms.ret == 1);
}

Test(check, do_exec_zero)
{
	char	*builtin[6] = {"cd", "exit", "env", "setenv", "unsetenv", NULL};
	bt_t	*bt = NULL;
	char	**env;
	mysh_t	ms;

	env = my_str_to_wordtab("ceci est un env", ' ');
	bt = init_values(&ms, env, bt);
	ms.exe = strdup("/bin/ls");
	ms.arg = my_str_to_wordtab("ls src", ' ');
	ms.env = tab_dup(env, 0);
	do_exec_zero(&ms, bt, -1);
	cr_assert(ms.ret == 0);
	ms.exe = strdup("/bin/cd");
	ms.arg = my_str_to_wordtab("cd src", ' ');
	do_exec_zero(&ms, bt, 0);
	cr_assert(ms.ret == 0);
}

Test(check, before_exec)
{
	char	*builtin[6] = {"cd", "exit", "env", "setenv", "unsetenv", NULL};
	bt_t	*bt = NULL;
	char	**env;
	mysh_t	ms;

	env = my_str_to_wordtab("ceci est un env", ' ');
	bt = init_values(&ms, env, bt);
	ms.mnv = my_str_to_wordtab("/bin", ' ');
	ms.arg = my_str_to_wordtab("ls src", ' ');
	ms.env = tab_dup(env, 0);
	before_exec(&ms, bt);
	cr_assert(ms.ret == 0);
	ms.arg = my_str_to_wordtab("laes src", ' ');
	before_exec(&ms, bt);
	cr_assert(ms.ret == 1);
	ms.arg = my_str_to_wordtab("exit 4", ' ');
	before_exec(&ms, bt);
	cr_assert(ms.ret == 4);
}

Test(check, transform_left)
{
	bt_t	*bt = NULL;
	char	**env;
	mysh_t	ms;

	env = my_str_to_wordtab("ceci est un env", ' ');
	bt = init_values(&ms, env, bt);
	ms.mnv = my_str_to_wordtab("/bin", ' ');
	ms.env = tab_dup(env, 0);
	ms.arg = my_str_to_wordtab("ls -l < test", ' ');
	ms.red = tab_dup(ms.arg, 0);
	transform_left(&ms, bt);
	cr_assert(ms.ret == 1);
}

Test(check, transform_right)
{
	bt_t	*bt = NULL;
	char	**env;
	mysh_t	ms;

	env = my_str_to_wordtab("ceci est un env", ' ');
	bt = init_values(&ms, env, bt);
	ms.mnv = my_str_to_wordtab("/bin", ' ');
	ms.env = tab_dup(env, 0);
	ms.arg = my_str_to_wordtab("ls -l > test", ' ');
	ms.red = tab_dup(ms.arg, 0);
	transform_right(&ms, bt);
	cr_assert(ms.ret == 0);
}