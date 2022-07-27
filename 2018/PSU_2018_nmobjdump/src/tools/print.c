/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** print
*/

#include "list.h"

void    print_info(list_t *list)
{
    for (;list != NULL; list = list->next) {
        if (list->addr == 0 && list->type != 'T')
            printf(" %17c %s\n", list->type, list->name);
        else
            printf("%016x %c %s\n", list->addr, list->type, list->name);
    }
}