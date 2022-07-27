/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** tests_function_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bitmap.h"

Test(make_bmp_header, init, .init = cr_redirect_stdout)
{
    bmp_header_t    *header = malloc(sizeof(*header));

    make_bmp_header(header, 5);
    cr_assert(header->magic == 0x4D42);
    cr_assert(header->size == 5 * 5 * 4 + 54);
    cr_assert(header->_app1 == 0);
    cr_assert(header->_app2 == 0);
    cr_assert(header->offset == 54);
}
