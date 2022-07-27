/*
** EPITECH PROJECT, 2018
** lem_in
** File description:
** units tests
*/

#include <criterion/criterion.h>
#include "my.h"

Test(check, isthere_apip)
{
	mysh_t	ms;

	ms.red = my_str_to_wordtab("ls > ls", ' ');
	cr_assert(isthere_apip(&ms) == 1);
	ms.red = my_str_to_wordtab("ls >> ls", ' ');
	cr_assert(isthere_apip(&ms) == 2);
	ms.red = my_str_to_wordtab("ls < ls", ' ');
	cr_assert(isthere_apip(&ms) == 3);
	ms.red = my_str_to_wordtab("ls << ls", ' ');
	cr_assert(isthere_apip(&ms) == 4);
	ms.red = my_str_to_wordtab("ls | ls", ' ');
	cr_assert(isthere_apip(&ms) == 5);
	ms.red = my_str_to_wordtab("ls || ls", ' ');
	cr_assert(isthere_apip(&ms) == 0);
	ms.red = my_str_to_wordtab("ls & ls", ' ');
	cr_assert(isthere_apip(&ms) == 0);
}

Test(check, the_cd)
{
	mysh_t	ms;
	char	*pwd = strdup("/home/nickauteen/delivery");

	ms.old_pwd = strdup("/home/nickauteen/delivery/Stumper");
	ms.arg = my_str_to_wordtab("cd -re", ' ');
	the_cd(&ms, pwd);
	cr_assert(ms.ret == 1);
	ms.old_pwd = strdup("/home/nickauteen/doigt");
	ms.arg = my_str_to_wordtab("cd -", ' ');
	the_cd(&ms, pwd);
	cr_assert(ms.ret == 1);
	ms.arg = my_str_to_wordtab("cd ~bruh", ' ');
	the_cd(&ms, pwd);
	cr_assert(ms.ret == 1);
}

Test(check, the_setenv)
{
	mysh_t	ms;

	ms.arg = my_str_to_wordtab("setenv 2re ca", ' ');
	the_setenv(3, &ms);
	cr_assert(ms.ret == 1);
	ms.arg = my_str_to_wordtab("setenv A?2re ca", ' ');
	the_setenv(3, &ms);
	cr_assert(ms.ret == 1);
	ms.env = my_str_to_wordtab("re=chatte ca=bite", ' ');
	ms.arg = my_str_to_wordtab("setenv re ca", ' ');
	the_setenv(3, &ms);
	cr_assert(ms.ret == 0);
	ms.arg = my_str_to_wordtab("setenv rea", ' ');
	the_setenv(2, &ms);
	cr_assert(ms.ret == 0);
}

Test(check, the_unsetenv)
{
	mysh_t 	ms;

	ms.env = my_str_to_wordtab("re=chatte ca=rite", ' ');
	ms.arg = my_str_to_wordtab("unsetenv re", ' ');
	the_unsetenv(&ms);
	cr_assert(strcmp(ms.env[0], "ca=rite") == 0);
}

Test(check, after_septab)
{
	char	**tab = my_str_to_wordtab("salut . mademoiselle", ' ');
	char	**cmp;

	cmp = after_septab(tab, '.');
	cr_assert(strcmp(cmp[0], tab[2]) == 0);
}