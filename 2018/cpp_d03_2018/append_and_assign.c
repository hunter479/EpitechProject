/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** append
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

void    append_s(string_t *this, const string_t *ap)
{
    int size = 0;
    char    *content = NULL;

    if (!this || !ap)
        return;
    size = strlen(this->str) + strlen(ap->str);
    content = malloc(size * sizeof(char) + 1);
    if (!content)
        return;
    content = strcpy(content, this->str);
    content = strcat(content, ap->str);
    this->str = strdup(content);
    free(content);
}

void    append_c(string_t *this, const char *ap)
{
    int size = 0;
    char    *content = NULL;

    if (!this || !ap)
        return;
    size = strlen(this->str) + strlen(ap);
    content = malloc(size * sizeof(char) + 1);
    if (!content)
        return;
    content = strcpy(content, this->str);
    content = strcat(content, ap);
    this->str = strdup(content);
    free(content);
}

void    assign_s(string_t *this, const string_t *str)
{
    if (!this || !str)
        return;
    if (str->str)
        this->str = strdup(str->str);
}

void    assign_c(string_t *this, const char *str)
{
    if (!this || !str)
        return;
    if (this->str)
        this->str = strdup(str);
}
