/*
** EPITECH PROJECT, 2018
** lem_in
** File description:
** units tests
*/

#include <criterion/criterion.h>
#include "my.h"

Test(check, check_argccess)
{
	mysh_t	ms;

	ms.arg = malloc(sizeof(char *));
	ms.arg[0] = NULL;
	cr_assert(check_argccess(&ms));
	ms.arg = malloc(sizeof(char *));
	ms.arg[0] = strdup("/bin/ls");
	ms.mnv = NULL;
	cr_assert(check_argccess(&ms) == 0);
	ms.mnv = malloc(sizeof(char *));
	ms.mnv[0] = strdup("aze");
	cr_assert(check_argccess(&ms) == 0);
	ms.mnv[0] = strdup("/bin");
	ms.arg[0] = strdup("ls");
	cr_assert(check_argccess(&ms) == 0);
	ms.mnv[0] = NULL;
	cr_assert(check_argccess(&ms) == 1);
}

Test(check, argcess_return)
{
	mysh_t	ms;
	char	*acc = strdup("oui");

	ms.arg = malloc(sizeof(char *));
	ms.arg[0] = strdup("../mysh");
	cr_assert(argccess_return(&ms, acc) == 1);
	ms.arg[0] = strdup("bojour");
	cr_assert(argccess_return(&ms, acc) == 0);
	ms.arg[0] = strdup("/bin/ls");
	acc = strdup("/bin/ls");
	cr_assert(argccess_return(&ms, acc) == 2);
}

Test(check, environnement)
{
	char	**env;
	char	**tab;
	char	**cmp;

	env = my_str_to_wordtab("PATH=oui:non Jesuisgay tranquille", ' ');
	tab = my_str_to_wordtab("oui non", ' ');
	cmp = environnement(env);
	cr_assert(strcmp(cmp[0], tab[0]) == 0);
	cr_assert(strcmp(cmp[1], tab[1]) == 0);
}