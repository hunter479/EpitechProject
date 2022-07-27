/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** day2
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mem_ptr.h"

void    add_str(const char *str1, const char *str2, char **res)
{
    int a = -1;
    int b = -1;

    *res = malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
    while (str1[++a] != '\0')
        (*res)[a] = str1[a];
    while (str2[++b] != '\0') {
        (*res)[a] = str2[b];
        a++;
    }
    (*res)[a] = '\0';
}

void    add_str_struct(str_op_t *str_op)
{
    int a = -1;
    int b = -1;
    int size = (strlen(str_op->str1) + strlen(str_op->str2) + 1);

    str_op->res = malloc(size * sizeof(char));
    while (str_op->str1[++a] != '\0')
        str_op->res[a] = str_op->str1[a];
    while (str_op->str2[++b] != '\0') {
        str_op->res[a] = str_op->str2[b];
        a++;
    }
    str_op->res[a] = '\0';
}
