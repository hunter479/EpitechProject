/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** tests_function_name
*/

#include <criterion/criterion.h>
#include "mem_ptr.h"

void    add_str_struct(str_op_t *str_op);

Test(add_str_struct, calcul)
{
    str_op_t    str_op;
    char    *str = "Hello World";

    str_op.str1 = "Hello ";
    str_op.str2 = "World";
    add_str_struct(&str_op);
    cr_assert(strcmp(str, str_op.res) == 0);
}
