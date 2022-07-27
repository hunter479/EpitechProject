/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** at_clear_size
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

char    at(const string_t *this, size_t pos)
{
    if (!this || !this->str)
        return (-1);
    if (pos > strlen(this->str))
        return (-1);
    if (this->str[pos] == '\0')
        return (-1);
    return (this->str[pos]);
}

int size(const string_t *this)
{
    if (!this || !this->str)
        return (-1);
    return (strlen(this->str));
}