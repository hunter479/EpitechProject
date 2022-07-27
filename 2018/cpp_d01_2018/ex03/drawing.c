/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** drawing
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "drawing.h"

void    draw_square(uint32_t **ig, const point_t *org, size_t s, uint32_t cr)
{
    int x = org->x;
    int y = org->y;

    while (y < s + org->y) {
        while (x < s + org->x) {
            ig[x][y] = cr;
            x++;
        }
        x = 0;
        y++;
    }
}