/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** free
*/

#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "malloc.h"

struct block *get_block(void *p)
{
    char *tmp = NULL;

    tmp = p;
    tmp -= 16;
    p = tmp;
    return (p);
}

int valid_addr(void *p)
{
    if (main_memory != NULL) {
        if (p > main_memory && p < sbrk(0))
            return (p == (get_block(p))->addr);
    }
    return (0);
}

void *addr_valid(block_t *b, void *p, size_t s)
{
    void *newp;

    b = get_block(p);
    if (b->size >= s) {
        if (b->size - s >= (16 + 4))
            split(b, s);
        return (p);
    }
    if (b->next && b->next->free &&
    (b->size + 16 + b->next->size) >= s) {
        fusion(b);
        if (b->size - s >= (16 + 4))
            split(b, s);
        return (p);
    }
    newp = malloc(s);
    if (!newp)
        return (NULL);
    free(p);
    return (newp);
}

void *realloc(void *p, size_t size)
{
    void *newp = NULL;
    block_t *b;

    size = align4(size);
    if (p == NULL)
        return (malloc(size));
    b = (block_t *)p - 1;
    if (b->size >= size) {
        b->free = 1;
        return (p);
    }
    if (valid_addr(p))
        return (addr_valid(b, p, size));
    newp = malloc(size);
    if (!newp)
        return (NULL);
    free(p);
    return (newp);
}