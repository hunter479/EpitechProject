/*
** EPITECH PROJECT, 2018
** lem_in
** File description:
** units tests
*/

#include <criterion/criterion.h>
#include "my.h"

Test(ret, countword)
{
	char	*a = "Je mange du poisson pane!";
	char	*b = "bite;chatte;cul;vergeture";
	char	*c = "je.suis.un.imbecile";

	cr_assert(countword(a, ' ') == 5);
	cr_assert(countword(b, ';') == 4);
	cr_assert(countword(c, '.') == 4);
}

Test(ret, my_strlent)
{
	char	*a = "Je mange du poisson pane!";
	char	*b = "bite;chatte;cul;vergeture";
	char	*c = "je.suis.un.imbecile";
	char	*d = "aime les gosses comme ils t'aiment";

	cr_assert(my_strlent(a, ' ') == 3);
	cr_assert(my_strlent(b, ';') == 5);
	cr_assert(my_strlent(c, '.') == 3);
	cr_assert(my_strlent(d, '.') == 35);
}

Test(check, free_struct)
{
	mysh_t	ms;

	ms.s = strdup("bonjour");
	ms.exe = strdup("madame");
	ms.pexe = strdup("fracture");
	ms.cat = strdup("retine");
	ms.old_pwd = strdup("jamais content");
	ms.com = my_str_to_wordtab("bonjour madame", ' ');
	ms.mnv = my_str_to_wordtab("hello darkness", ' ');
	ms.arg = my_str_to_wordtab("ls -l -a", ' ');
	ms.red = my_str_to_wordtab("encore un voyageur", ' ');
	ms.env = my_str_to_wordtab("j'ai envie d'une glace", ' ');
	cr_assert(ms.s);
}

Test(ret, good_redirect)
{
	char	*a = "ls >";
	char	*b = "ls <<";
	char	*c = "ls >< ds";
	char	*d = "ls >>< ls";
	char	*e = "ls >> < ds";
	char	*f = "ls > ds";

	cr_assert(good_redirect(a, 3) == 1);
	cr_assert(good_redirect(b, 3) == 1);
	cr_assert(good_redirect(c, 3) == 1);
	cr_assert(good_redirect(d, 3) == 1);
	cr_assert(good_redirect(e, 3) == 1);
	cr_assert(good_redirect(f, 3) == 0);
}

Test(check, argcces_slash)
{
	mysh_t	ms;

	ms.arg = malloc(sizeof(char *));
	ms.arg[0] = strdup("/bin/ls");
	cr_assert(argccess_slash(&ms) == 2);
	ms.arg[0] = strdup("./ls");
	cr_assert(argccess_slash(&ms) == 1);
}