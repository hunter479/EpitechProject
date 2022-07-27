/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** append_and_assign
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

const char  *c_str(const string_t *this)
{
    return (this->str);
}

int to_int(const string_t *this)
{
    if (!this || !this->str)
        return (84);
    return (atoi(this->str));
}
