/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** tests_function_name
*/

#include <criterion/criterion.h>

void    add_str(const char *str1, const char *str2, char **res);

Test(add_mul_2param, calcul)
{
    char    *str = "Hello World";
    char    *final;

    add_str("Hello ", "World", &final);
    cr_assert(strcmp(str, final) == 0);
}