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

bool_t  list_del_elem_at_front(list_t *front_ptr)
{
    if (!(*front_ptr))
        return (FALSE);
    (*front_ptr) = (*front_ptr)->next;
    return (TRUE);
}

bool_t  list_del_elem_at_back(list_t *front_ptr)
{
    list_t  tmp = (*front_ptr)->next;
    list_t  behind = *front_ptr;

    if (!behind)
        return (FALSE);
    while (tmp->next != NULL) {
        behind = behind->next;
        tmp = tmp->next;
    }
    behind->next = NULL;
    return (TRUE);
}

bool_t  list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    unsigned int loop = 1;
    list_t  before = *front_ptr;
    list_t  after = *front_ptr;

    if (position > list_get_size(after) || !after)
        return (FALSE);
    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    while (loop < position) {
        after = after->next;
        loop++;
    }
    for (int a = 0; a < 2; a++) {
        if (after->next)
            after = after->next;
    }
    before->next = after;
    return (TRUE);
}
