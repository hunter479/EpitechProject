/*
** EPITECH PROJECT, 2019
** cpp_d02m_2018
** File description:
** tests_print_upper
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void    print_upper(const char *str);

Test(print_upper, display, .init = cr_redirect_stdout)
{
    print_upper("hello");
    fflush(stdout);
    cr_assert_stdout_eq_str("HELLO\n");
}
