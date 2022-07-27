/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** tests_function_name
*/

#include <criterion/criterion.h>

void add_mul_4param(int, int, int *, int *);

Test(add_mul_4param, calcul)
{
    int first = 3;
    int second = 7;
    int sum;
    int product;

    add_mul_4param(first, second, &sum, &product);
    cr_assert(sum == second + first);
    cr_assert(product == second * first);
}
