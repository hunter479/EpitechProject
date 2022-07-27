/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** find_and_insert
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char    *locate = NULL;

    if (!this || !this->str || !str || !str->str || pos > strlen(str->str))
        return (-1);
    locate = strstr(this->str + pos, str->str);
    if (!locate)
        return (-1);
    return (locate - this->str);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char    *locate = NULL;

    if (!this || !this->str || !str || pos > strlen(str))
        return (-1);
    locate = strstr(this->str + pos, str);
    if (!locate)
        return (-1);
    return (locate - this->str);
}

void    insert_c(string_t *this, size_t pos, const char *str)
{
    size_t  i = 0;
    size_t  a = 0;
    size_t  pos1 = 0;
    char    *tmp = NULL;

    if (pos > strlen(str))
        return;
    tmp = malloc((strlen(str) + strlen(this->str)) * sizeof(char));
    while (str[i] != '\0' && i < pos)
        tmp[pos1++] = str[i++];
    while (this->str[a] != '\0')
            tmp[pos1++] = this->str[a++];
    while (str[i] != '\0')
        tmp[pos1++] = str[i++];
    tmp[pos1] = '\0';
    this->str = tmp;
}

void    insert_s(string_t *this, size_t pos, const string_t *str)
{
    size_t  i = 0;
    size_t  a = 0;
    size_t  pos1 = 0;
    char    *tmp = NULL;

    if (pos > strlen(str->str))
        return;
    tmp = malloc((strlen(str->str) + strlen(this->str)) * sizeof(char));
    while (str->str[i] != '\0' && i < pos)
        tmp[pos1++] = str->str[i++];
    while (this->str[a] != '\0')
            tmp[pos1++] = this->str[a++];
    while (str->str[i] != '\0')
        tmp[pos1++] = str->str[i++];
    tmp[pos1] = '\0';
    this->str = tmp;
}
