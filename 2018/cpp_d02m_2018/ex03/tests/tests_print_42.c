/*
** EPITECH PROJECT, 2019
** cpp_d02m_2018
** File description:
** tests_print_42
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void    print_42(const char *str);

Test(print_42, display, .init = cr_redirect_stdout)
{
    print_42("42");
    fflush(stdout);
    cr_assert_stdout_eq_str("42\n");
}
