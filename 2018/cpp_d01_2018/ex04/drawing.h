/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** drawing
*/

#ifndef DRAWING_H_
	#define DRAWING_H_

#include <stdint.h>

typedef struct s_point
{
    uint32_t    x;
    uint32_t    y;
} point_t;

void    draw_square(uint32_t **, const point_t *, size_t, uint32_t);
void    write_bmp_header(int, size_t);
void    write_bmp_info_header(int, size_t);
void    create_bitmap_from_buffer(size_t, unsigned int *, char *);

#endif /* !DRAWING_H_ */
