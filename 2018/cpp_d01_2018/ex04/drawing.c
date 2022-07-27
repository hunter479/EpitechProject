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
#include <stddef.h>
#include "bitmap.h"
#include "drawing.h"
#include "menger.h"

void    write_bmp_header(int fd, size_t size)
{
    bmp_header_t header;

    make_bmp_header(&header, size);
    write(fd, &header, sizeof(header));
}

void    write_bmp_info_header(int fd, size_t size)
{
    bmp_info_header_t info;

    make_bmp_info_header(&info, size);
    write(fd, &info, sizeof(info));
}

void    draw_square(uint32_t **ig, const point_t *org, size_t s, uint32_t cr)
{
    uint32_t x = org->x;
    uint32_t y = org->y;

    while (y < s + org->y) {
        while (x < s + org->x) {
            ig[x][y] = cr;
            x++;
        }
        x = org->x;
        y++;
    }
}

void    create_bitmap_from_buffer(size_t size, unsigned int *buffer, char *nm)
{
    int fd = open(nm, O_CREAT | O_TRUNC | O_WRONLY, 0644);

    write_bmp_header(fd, size);
    write_bmp_info_header(fd, size);
    write(fd, buffer, size * size * sizeof(*buffer));
    close(fd);
}
