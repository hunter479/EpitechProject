/*
** EPITECH PROJECT, 2019
** chained list
** File description:
** day02a
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "generic_list.h"

unsigned int    list_get_size(list_t list)
{
    int a = 0;

    while (list) {
        list = list->next;
        a++;
    }
    return (a);
}

void    list_clear(list_t *front)
{
    list_t  one_step = (*front)->next ? (*front)->next : NULL;
    list_t  tmp = *front;

    while (one_step && one_step->next) {
        free(tmp);
        tmp = one_step;
        one_step = one_step->next;
    }
    if (!tmp)
        free(tmp);
}

bool_t  list_is_empty(list_t list)
{
    if (list)
        return (FALSE);
    else
        return (TRUE);
}

void    list_dump(list_t list, value_displayer_t val_disp)
{
    while (list) {
        val_disp(list->value);
        list = list->next;
    }
}
