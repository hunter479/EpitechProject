/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** tests_function_name
*/

#include <criterion/criterion.h>

void add_mul_2param(int *, int *);

Test(add_mul_2param, calcul)
{
    int first = 3;
    int second = 7;

    add_mul_2param(&first, &second);
    cr_assert(first == 10);
    cr_assert(second == 21);
}