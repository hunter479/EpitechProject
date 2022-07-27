/*
** EPITECH PROJECT, 2019
** chained list
** File description:
** day02a
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

unsigned int    list_get_size(list_t list)
{
    unsigned int a = 0;

    while (list) {
        list = list->next;
        a++;
    }
    return (a);
}

bool_t  list_is_empty(list_t list)
{
    if (list)
        return (FALSE);
    else
        return (TRUE);
}

void    list_dump(list_t list)
{
    while (list) {
        printf("%f\n", list->value);
        list = list->next;
    }
}
