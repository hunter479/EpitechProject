/*
** EPITECH PROJECT, 2019
** malloc
** File description:
** malloc
*/

#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "malloc.h"

block_t *find_free(block_t **last_block, size_t size)
{
    block_t *memory = *last_block;

    while (memory != NULL && !(memory->free != 0 && memory->size >= size)) {
        *last_block = memory;
        memory = memory->next;
    }
    return (memory);
}

block_t *get_space(block_t *last_block, size_t size)
{
    block_t    *new_block;
    void            *request;

    new_block = sbrk(0);
    request = sbrk(size + sizeof(block_t));
    if (request == (void *) -1)
        return (NULL);
    if (last_block != NULL)
        last_block->next = new_block;
    new_block->size = size;
    new_block->free = 0;
    new_block->next = NULL;
    new_block->prev = last_block;
    new_block->addr = request + sizeof(block_t);
    return (new_block);
}

void split(block_t *b, size_t s)
{
    block_t *new = NULL;

    new = b->addr + s;
    new->size = b->size - s - sizeof(block_t);
    new->free = 1;
    new->next = b->next;
    if (new->next)
        new->next->prev = new;
    new->prev = b;
    new->addr = b->addr + s + sizeof(block_t);
    b->size = s;
    b->next = new;
}

void *first_time(size_t size)
{
    block_t *block = NULL;

    block = get_space(NULL, size);
    if (block == NULL)
        return (NULL);
    main_memory = block;
    return (block->addr);
}

void *malloc(size_t size)
{
    block_t *block;
    block_t *last_block = main_memory;

    if (size <= 0)
        return (NULL);
    size = align4(size);
    if (main_memory == NULL)
        return (first_time(size));
    block = find_free(&last_block, size);
    if (block == NULL)
        block = get_space(last_block, size);
    else {
        if (block->size - size >= sizeof(block_t) + 4)
            split(block, size);
        block->free = 0;
    }
    if (block == NULL)
        return (NULL);
    return (block->addr);
}

