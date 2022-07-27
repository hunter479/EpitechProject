/*
** EPITECH PROJECT, 2019
** cpp_d02m_2018
** File description:
** tests_do_action
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "func_ptr.h"

void    do_action(action_t action, const char *str);

Test(do_action, display, .init = cr_redirect_stdout)
{
    do_action(PRINT_NORMAL, "Hello");
    fflush(stdout);
    do_action(PRINT_REVERSE, "Hello");
    fflush(stdout);
    do_action(PRINT_UPPER, "Hello");
    fflush(stdout);
    do_action(PRINT_42, "Hello");
    fflush(stdout);
    cr_assert_stdout_eq_str("Hello\nolleH\nHELLO\n42\n");
}