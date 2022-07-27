/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** tests_function_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "menger.h"

Test(getnbr, result, .init = cr_redirect_stdout)
{
    cr_assert(my_getnbr("42") == 42);
}
