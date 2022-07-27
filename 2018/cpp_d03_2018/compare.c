/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** compare
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}
