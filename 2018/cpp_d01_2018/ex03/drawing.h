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

#endif /* !DRAWING_H_ */
