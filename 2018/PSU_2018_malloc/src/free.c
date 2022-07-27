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

struct block *fusion(struct block *block)
{
    if (block == NULL)
        return (block);
    if (block->next && block->next->free == 1) {
        block->size += (sizeof(block_t)) + block->next->size;
        if (block->next->next == NULL)
            block->next = NULL;
        else
            block->next = block->next->next;
        if (block->next != NULL)
            block->next->prev = block;
    }
    return (block);
}

void free(void *to_free)
{
    struct block *block;

    main_memory = main_memory;
    if (to_free == NULL)
        return;
    block = (struct block *)to_free - 1;
    block->free = 1;
    if (block->prev && block->prev->free == 1)
        block = fusion(block->prev);
}
