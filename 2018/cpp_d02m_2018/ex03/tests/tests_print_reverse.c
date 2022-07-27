/*
** EPITECH PROJECT, 2019
** cpp_d02m_2018
** File description:
** tests_print_reverse
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void    print_reverse(const char *str);

Test(print_reverse, display, .init = cr_redirect_stdout)
{
    print_reverse("OK");
    fflush(stdout);
    cr_assert_stdout_eq_str("KO\n");
}
