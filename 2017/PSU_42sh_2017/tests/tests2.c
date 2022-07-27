/*
** EPITECH PROJECT, 2018
** lem_in
** File description:
** units tests
*/

#include <criterion/criterion.h>
#include "my.h"

Test(ret, wrong_direction)
{
	mysh_t	ms;
	char	*a = "ls >> aze";
	char	*b = "az < aze";
	char	*c = "ls >< ls";
	char	*d = "ls > | ls";
	char	*e = "ls >|< ls";

	wrong_direction(&ms, a, 3);
	cr_assert(ms.ret == 0);
	wrong_direction(&ms, b, 3);
	cr_assert(ms.ret == 0);
	wrong_direction(&ms, c, 3);
	cr_assert(ms.ret == 1);
	wrong_direction(&ms, d, 3);
	cr_assert(ms.ret == 1);
	wrong_direction(&ms, e, 3);
	cr_assert(ms.ret == 1);
}

Test(ret, pigrsp)
{
	char	a = ' ';
	char	b = '>';
	char	c = '<';
	char	d = '|';
	char	e = 'a';

	cr_assert(pigrsp(a) == 2);
	cr_assert(pigrsp(b) == 1);
	cr_assert(pigrsp(c) == 1);
	cr_assert(pigrsp(d) == 1);
	cr_assert(pigrsp(e) == 0);
}

Test(ret, wrong_pipe)
{
	mysh_t	ms;
	char	*a = "| aze";
	char	*b = "aze |";
	char	*c = "aze | | aze";
	char	*d = "aze | aze";

	cr_assert(wrong_pipe(&ms, a, 0) == 1);
	cr_assert(wrong_pipe(&ms, b, 4) == 1);
	cr_assert(wrong_pipe(&ms, c, 4) == 1);
	cr_assert(wrong_pipe(&ms, d, 4) == 0);
}

Test(check, my_str_to_wordtab)
{
	char	**a = NULL;
	char	*as = "Je ;suis; un;gogole.";
	char	*a1 = "Je ";
	char	*a2 = "suis";
	char	*a3 = " un";
	char	*a4 = "gogole.";

	a = my_str_to_wordtab(as, ';');
	cr_assert(strcmp(a[0], a1) == 0);
	cr_assert(strcmp(a[1], a2) == 0);
	cr_assert(strcmp(a[2], a3) == 0);
	cr_assert(strcmp(a[3], a4) == 0);
	cr_assert(a[4] == NULL);
}

Test(check, my_str_to_wordtab2)
{
	char	**a;
	char	*as = "Je mange du papier";
	char	*a1 = "Je";
	char	*a2 = "mange";
	char	*a3 = "du";
	char	*a4 = "papier";

	a = my_str_to_wordtab(as, ' ');
	cr_assert(strcmp(a[0], a1) == 0);
	cr_assert(strcmp(a[1], a2) == 0);
	cr_assert(strcmp(a[2], a3) == 0);
	cr_assert(strcmp(a[3], a4) == 0);
	cr_assert(a[4] == NULL);
}
