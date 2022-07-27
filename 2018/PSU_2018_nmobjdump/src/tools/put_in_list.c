/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** put_in_list
*/

#include <unistd.h>
#include <stdlib.h>
#include "list.h"

void    clean_list(list_t **list)
{
    list_t *tmp = NULL;

    if (!(*list))
        return;
    tmp = (*list)->next;
    while (tmp != NULL) {
        free(*list);
        *list = tmp;
        tmp = tmp->next;
    }
    free(*list);
    *list = NULL;
}

list_t *create_list(int addr, char type, char *name)
{
    list_t *box = malloc(sizeof(list_t));

    if (!box)
        return (NULL);
    box->addr = addr;
    box->type = type;
    box->name = name;
    box->next = NULL;
    return (box);
}

void put_in_list(list_t **list, list_t *elem)
{
    list_t *tmp = *list;

    if (tmp == NULL) {
        *list = elem;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elem;
}