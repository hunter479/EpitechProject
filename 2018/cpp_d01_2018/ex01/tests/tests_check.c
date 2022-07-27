/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** tests_function_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "menger.h"

Test(check, result, .init = cr_redirect_stdout)
{
    cr_assert(check(0, 1) == 84);
    cr_assert(check(2, 0) == 84);
    cr_assert(check(30, 30) == 84);
    cr_assert(check(3, 1) == 0);
}
