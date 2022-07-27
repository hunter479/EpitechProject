/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** pool 02
*/

#include <stdio.h>
#include "bitmap.h"
#include "drawing.h"
#include "menger.h"

int check(int size, int level)
{
    if (size <= 0)
        return (84);
    else if (level <= 0)
        return (84);
    if (size >= (level * level * level))
        return (0);
    return (84);
}

int color_sama(unsigned char r, unsigned char g, unsigned char b)
{
    int color;

    color = r << 16 | g << 8 | b;
    return (color);
}

void    menger(int size, int lvl, meng_t pos, uint32_t **img)
{
    meng_t  pos_new = pos;
    point_t p = {size / 3 + pos.x, size / 3 + pos.y};

    if (lvl < 1 || size < 1 )
        return;
    draw_square(img, &p, size / 3, color_sama(255 / lvl, 255 / lvl, 255 / lvl));
    while (pos_new.x < size + pos.x) {
        menger(size / 3, lvl - 1, pos_new, img);
        pos_new.y += size / 3;
        if (pos_new.y >= size + pos.y) {
            pos_new.y = pos.y;
            pos_new.x += size / 3;
        }
        if (pos_new.y == size / 3 + pos.y && pos_new.x == size / 3 + pos.x)
            pos_new.y += size / 3;
    }
}