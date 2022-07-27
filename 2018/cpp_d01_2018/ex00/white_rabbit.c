/*
** EPITECH PROJECT, 2019
** White Rabbit
** File description:
** ex00
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int follow_the_white_rabbit(void)
{
    int    die = 0;
    int    somme = 0;

    while (die != 1 && die != 37) {
        die = (random() % 37) + 1;
        if (die == 26 || die % 8 == 0)
            printf ("backward\n");
        if ((die >= 4 && die <= 6) ||  (die >= 17 && die <= 21) || die == 28)
            printf ("left\n");
        if ((die >= 34 && die <= 36) || die == 13)
            printf ("right\n");
        if (die == 10 || die == 15 || die == 23)
            printf ("forward\n");
        somme += die;
        if (somme >= 397)
            die = 1;
    }
    printf ("RABBIT!!!\n");
    return (somme);
}
