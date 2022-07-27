/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** tests_function_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "menger.h"

Test(menger, result, .init = cr_redirect_stdout)
{
    menger(9, 1, 0, 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("003 003 003\n");
}

Test(menger, result2, .init = cr_redirect_stdout)
{
    menger(9, 2, 0, 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("003 003 003\n001 001 001\n001 001 004\n001 001 007\n001 004 001\n001 004 007\n001 007 001\n001 007 004\n001 007 007\n");

}
