/*
** EPITECH PROJECT, 2019
** menger
** File description:
** day02
*/

#include <stdlib.h>
#include <string.h>
#include "bitmap.h"
#include "drawing.h"
#include "menger.h"

void    initialize_image(size_t size, unsigned int *buffer, unsigned int **img)
{
    memset(buffer, 0, size * size * sizeof(*buffer));
    for (size_t i = 0; i < size; ++i)
        img[i] = buffer + i * size;
}

int do_it(char **av)
{
    int size = atoi(av[2]);
    int level = atoi(av[3]);
    unsigned int *buffer = malloc(size * size * sizeof(*buffer));
    unsigned int **img = malloc(size * size * sizeof(*img));
    meng_t  coord;

    coord.x = 0;
    coord.y = 0;
    initialize_image(size, buffer, img);
    menger(size, level, coord, img);
    create_bitmap_from_buffer(size, buffer, av[1]);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (84);
    if (check(atoi(av[2]), atoi(av[3])) == 84)
        return (84);
    do_it(av);
    return (0);
}
