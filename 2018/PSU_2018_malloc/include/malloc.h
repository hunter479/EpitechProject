/*
** EPITECH PROJECT, 2019
** PSU_2018_malloc
** File description:
** malloc
*/

#ifndef MALLOC_H_
# define MALLOC_H_

#define align4(x) (((((x)-1)>>2)<<2)+4)

typedef struct block
{
    size_t          size;
    int             free;
    struct block    *next;
    struct block    *prev;
    void            *addr;
}   block_t;

static void *main_memory = NULL;

struct block *fusion(struct block *block);
void free(void *to_free);
struct block *get_block(void *p);
int valid_addr(void *p);
void *malloc(size_t size);
void *first_time(size_t size);
void split(block_t *b, size_t s);
struct block *get_space(struct block *last_block, size_t size);
struct block *find_free(struct block **last_block, size_t size);

#endif /* !MALLOC_H_ */
