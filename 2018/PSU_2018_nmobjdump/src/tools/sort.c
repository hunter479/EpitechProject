/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** function to sort
*/

#include <unistd.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "list.h"

int value_check(list_t *a, list_t *b)
{
    int k = 0;

    setlocale(LC_COLLATE, "en_US");
    k = strcoll(a->name, b->name);
    if (k != 0)
        return (k);
    if (a->addr < b->addr)
        return (-1);
    else
        return (1);
}

list_t	*sorted_merge_file(list_t *a, list_t *b)
{
    list_t	*result = NULL;
    int	k = 0;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    k = value_check(a, b);
    if (k < 0) {
        result = a;
        result->next = sorted_merge_file(a->next, b);
    }
    else {
        result = b;
        result->next = sorted_merge_file(a, b->next);
    }
    return (result);
}

void	split(list_t *source, list_t **front, list_t **back)
{
    list_t *fast;
    list_t *slow;

    if (source == NULL || source->next == NULL) {
        *front = source;
        *back = NULL;
        return;
    }
    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void	sort(list_t **headref)
{
    list_t *head = *headref;
    list_t *a = NULL;
    list_t *b = NULL;

    if (!head || !(head->next))
        return;
    split(head, &a, &b);
    sort(&a);
    sort(&b);
    *headref = sorted_merge_file(a, b);
}
