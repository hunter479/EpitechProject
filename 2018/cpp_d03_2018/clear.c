/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** clear
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

void    string_destroy(string_t *this)
{
    if (!this || !this->str)
        return;
    free(this->str);
}

size_t  copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t  i = 0;
    size_t  a = 0;

    if (!s || !this->str || n == 0 || pos > strlen(s))
        return (0);
    while (i < n) {
        if (i >= pos && this->str[a] != '\0') {
            s[i] = this->str[a];
            a++;
        }
        i++;
    }
    if (this->str[a] == '\0' && i < pos)
        i++;
    return (i);
}

int empty(const string_t *this)
{
    if (!this)
        return (1);
    if (this->str)
        return (0);
    else
        return (1);
}

void    clear(string_t *this)
{
    if (!this || !this->str)
        return;
    this->str = memset(this->str, 0, strlen(this->str));
}