/*
** EPITECH PROJECT, 2018
** lem_in
** File description:
** units tests
*/

#include <criterion/criterion.h>
#include "my.h"

Test(check, clear_str)
{
	char	*sp = "    re  e r fa    ";
	char	*tb = "\tre    p\t  ea \t\t\t  e. ";
	char	*pr = "> d>s <a |p| k >   < |   ";
	char	*sc = "pwp;cadp; a ;p;d ; ;  p ;; ; ;;";

	cr_assert(strcmp(clear_str(sp, 0), "re e r fa") == 0);
	cr_assert(strcmp(clear_str(tb, 0), "re p ea e.") == 0);
	cr_assert(strcmp(clear_str(pr, 1), "> d > s < a | p | k > < |") == 0);
	cr_assert(strcmp(clear_str(sc, 0), "pwp;cadp; a ;p;d ; ; p") == 0);
}

Test(ret, ambigo)
{
	mysh_t	ms;
	char	*al = "aze < aze < aze";
	char	*ap = "aze | aze < aze";
	char	*arr = "aze > aze > aze";
	char	*arp = "aze > aze | aze";
	char	*na = "aze > aze < aze";
	char	*np = "aze | aze | aze";

	ms.ret = 0;
	cr_assert(ambigo(&ms, al) == 1);
	cr_assert(ambigo(&ms, ap) == 1);
	cr_assert(ambigo(&ms, arr) == 1);
	cr_assert(ambigo(&ms, arp) == 1);
	cr_assert(ambigo(&ms, na) == 0);
	cr_assert(ambigo(&ms, np) == 0);
}

Test(ret, good_format)
{
	char	*a = "> la";
	char	*b = ">>> la";
	char	*c = ">> < la";
	char	*d = ">> <> la";
	char	*e = ">> <> la >>> ls";

	cr_assert(good_format(a) == 0);
	cr_assert(good_format(b) == 1);
	cr_assert(good_format(c) == 1);
	cr_assert(good_format(d) == 2);
	cr_assert(good_format(e) == 3);
}

Test(ret, wrong_redir)
{
	mysh_t	ms;
	char	*a = ">| l";
	char	*b = "> > l";
	char	*c = ">>< l";
	char	*d = ">> | l";
	char	*e = "l >";
	char	*f = "ah > ?";

	cr_assert(wrong_redir(&ms, a, 0) == 1);
	cr_assert(wrong_redir(&ms, b, 0) == 1);
	cr_assert(wrong_redir(&ms, c, 0) == 1);
	cr_assert(wrong_redir(&ms, d, 0) == 1);
	cr_assert(wrong_redir(&ms, e, 2) == 1);
	cr_assert(wrong_redir(&ms, f, 3) == 0);
}

Test(ret, check_invalid)
{
	mysh_t	ms;
	char	*a = "> ls";
	char	*b = "> ls az";
	char	*c = ">> ls";
	char	*d = ">> ls az";

	cr_assert(check_invalid(&ms, a) == 1);
	cr_assert(check_invalid(&ms, b) == 0);
	cr_assert(check_invalid(&ms, c) == 1);
	cr_assert(check_invalid(&ms, d) == 0);
}