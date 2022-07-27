/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** tests_function_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void    print_normal(const char *str);

Test(print_normal, display, .init = cr_redirect_stdout)
{
    print_normal("Hello!");
    fflush(stdout);
    cr_assert_stdout_eq_str("Hello!\n");
}
