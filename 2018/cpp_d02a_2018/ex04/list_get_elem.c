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

void  *list_get_elem_at_front(list_t list)
{
    if (!list)
        return (0);
    return (list->value);
}

void  *list_get_elem_at_back(list_t list)
{
    if (!list)
        return (0);
    while (list->next)
        list = list->next;
    return (list->value);
}

void  *list_get_elem_at_position(list_t list, unsigned int position)
{
    unsigned int a = 1;

    if (!list || position > list_get_size(list))
        return (0);
    if (position == 0)
        return (list_get_elem_at_front(list));
    while (list && a < position) {
        list = list->next;
        a++;
    }
    return (list->value);
}

node_t  *list_get_first_node_with_value(list_t list, void *value,
value_comparator_t val_comp)
{
    while (list) {
        if (val_comp(list->value, value) == 0)
            return (list);
        else
            list = list->next;
    }
    return (NULL);
}
