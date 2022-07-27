/*
** EPITECH PROJECT, 2018
** lem_in
** File description:
** units tests
*/

#include <criterion/criterion.h>
#include "my.h"

Test(check, command)
{
	mysh_t	ms;
	bt_t	*bt = NULL;
	char	**env;
	char	*tmp = strdup("ceci est un env");

	env = my_str_to_wordtab(tmp, ' ');
	bt = init_values(&ms, env, bt);
	cr_assert(command(&ms, bt, "cd") == 0);
	cr_assert(command(&ms, bt, "exit") == 0);
	cr_assert(command(&ms, bt, "unsetenv") == 1);
}

Test(check, send_command)
{
	mysh_t	ms;
	bt_t	*bt = NULL;
	char	**env;
	char	*tmp = strdup("ceci est un env");

	env = my_str_to_wordtab(tmp, ' ');
	bt = init_values(&ms, env, bt);
	ms.s = strdup("env;cd");
	cr_assert(send_command(&ms, bt) == 0);
}

Test(check, the_exit)
{
	mysh_t	ms;

	ms.arg = malloc(sizeof(char *) * 2);
	ms.arg[0] = strdup("exit");
	ms.arg[1] = strdup("8");
	the_exit(&ms);
	cr_assert(ms.ret == 8);
	ms.arg[1] = strdup("8t");
	the_exit(&ms);
	cr_assert(ms.ret == 1);
	ms.arg[1] = strdup("t1");
	the_exit(&ms);
	cr_assert(ms.ret == 1);
}

Test(check, isthere_another)
{
	mysh_t	ms;
	char	**tab = my_str_to_wordtab("ls > lel -l", ' ');
	char	**cmp = my_str_to_wordtab("ls -l", ' ');
	char	**tmp;

	ms.red = tab_dup(tab, 0);
	tmp = isthere_another(&ms, tab);
	cr_assert(strcmp(tmp[0], cmp[0]) == 0);
	cr_assert(strcmp(tmp[1], cmp[1]) == 0);
	tab = my_str_to_wordtab("ls | pwd", ' ');
	cmp = my_str_to_wordtab("ls", ' ');
	ms.red = tab_dup(tab, 0);
	tmp = isthere_another(&ms, tab);
	cr_assert(strcmp(tmp[0], cmp[0]) == 0);
}