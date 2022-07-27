/*
** EPITECH PROJECT, 2018
** lem_in
** File description:
** units tests
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include "my.h"

Test(check, add_pwd)
{
	char	**tab = my_str_to_wordtab("ls -l", ' ');
	char	*pwd;

	pwd = getcwd(NULL, 0);
	tab = add_pwd(tab);
	cr_assert(strcmp(tab[2], pwd) == 0);
}

Test(check, tab_dup)
{
	char	**tab = my_str_to_wordtab("salut monsieur", ' ');
	char	**ret;

	ret = tab_dup(tab, 0);
	cr_assert(strcmp(tab[0], ret[0]) == 0);
	cr_assert(strcmp(tab[1], ret[1]) == 0);
	ret = tab_dup(tab, 1);
	cr_assert(strcmp(tab[1], ret[0]) == 0);
}

Test(check, tab_cat)
{
	char	**tab1 = my_str_to_wordtab("je susi ki", ' ');
	char	**tab2 = my_str_to_wordtab("c mwa el patro", ' ');
	char	**ret;

	ret = tab_cat(tab1, tab2);
	cr_assert(strcmp(ret[0], tab1[0]) == 0);
	cr_assert(strcmp(ret[1], tab1[1]) == 0);
	cr_assert(strcmp(ret[2], tab1[2]) == 0);
	cr_assert(strcmp(ret[3], tab2[0]) == 0);
	cr_assert(strcmp(ret[4], tab2[1]) == 0);
	cr_assert(strcmp(ret[5], tab2[2]) == 0);
	cr_assert(strcmp(ret[6], tab2[3]) == 0);
}

Test(check, find_file)
{
	char	**tab = my_str_to_wordtab("ls > bonjour", ' ');
	char	*ret;

	ret = find_file(tab, '>');
	cr_assert(strcmp(ret, "bonjour") == 0);
	tab = my_str_to_wordtab("ls < salo", ' ');
	ret = find_file(tab, '<');
	cr_assert(strcmp(ret, "salo") == 0);
}

Test(check, simple_left)
{
	mysh_t	ms;

	ms.file = strdup("Makefile");
	cr_assert(simple_left(&ms) == 0);
	ms.file = strdup("moustique");
	cr_assert(simple_left(&ms) == 1);
}