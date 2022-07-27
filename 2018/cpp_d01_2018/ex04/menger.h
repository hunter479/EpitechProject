/*
** EPITECH PROJECT, 2019
** menger
** File description:
** menger
*/

#ifndef MENGER_H_
	#define MENGER_H_

#include <stdint.h>

typedef struct  s_coord_meng
{
    int x;
    int y;
}   meng_t;

int check(int, int);
void    menger(int size, int level, meng_t pos, uint32_t **img);

#endif /* !MENGER_H_ */
