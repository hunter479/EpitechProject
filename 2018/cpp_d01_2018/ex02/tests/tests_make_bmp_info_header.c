/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** tests_function_name
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bitmap.h"

Test(make_bmp_info_header, init, .init = cr_redirect_stdout)
{
    bmp_info_header_t    *header = malloc(sizeof(*header));

    make_bmp_info_header(header, 5);
    cr_assert(header->size == 40);
    cr_assert(header->width == 5);
    cr_assert(header->height == 5);
    cr_assert(header->planes == 1);
    cr_assert(header->bpp == 32);
    cr_assert(header->compression == 0);
    cr_assert(header->raw_data_size == 5 * 5 * 4);
    cr_assert(header->h_resolution == 0);
    cr_assert(header->v_resolution == 0);
    cr_assert(header->palette_size == 0);
    cr_assert(header->important_colors == 0);
}