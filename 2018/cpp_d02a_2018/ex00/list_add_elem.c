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

bool_t  list_add_elem_at_front(list_t *front_ptr, double elem)
{
    list_t  new = malloc(sizeof(*new));

    if (!new)
        return (FALSE);
    new->value = elem;
    new->next = NULL;
    if (*front_ptr)
        new->next = *front_ptr;
    *front_ptr = new;
    return (TRUE);
}

bool_t  list_add_elem_at_back(list_t *front_ptr, double elem)
{
    list_t end = *front_ptr;
    list_t new = malloc(sizeof(*new));

    if (!new)
        return (FALSE);
    new->value = elem;
    new->next = NULL;
    if (!end) {
        *front_ptr = new;
        return (TRUE);
    }
    while (end->next != NULL)
        end = end->next;
    end->next = new;
    return (TRUE);
}

bool_t  list_add_elem_at_position(list_t *front_ptr, double elem,
unsigned int position)
{
    unsigned int loop = 1;
    list_t  new = malloc(sizeof(*new));
    list_t  tmp = *front_ptr;

    if (!new || position > list_get_size(*front_ptr))
        return (FALSE);
    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    new->value = elem;
    new->next = NULL;
    while (loop < position) {
        tmp = tmp->next;
        loop++;
    }
    new->next = tmp->next;
    tmp->next = new;
    return (TRUE);
}
