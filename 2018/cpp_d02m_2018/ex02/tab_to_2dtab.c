/*
** EPITECH PROJECT, 2019
** tab to 2dtab
** File description:
** ex02
*/

#include <stdlib.h>

void    tab_to_2dtab(const int *tab, int lenght, int width, int ***res)
{
    int y = 0;
    int x = 0;
    int a = 0;

    (*res) = malloc(lenght * sizeof(int *));
    (*res)[0] = malloc(width * sizeof(int));
    while (y < lenght) {
        while (x < width) {
            (*res)[y][x] = tab[a];
            a++;
            x++;
        }
        y++;
        (*res)[y] = malloc(width * sizeof(int));
        x = 0;
    }
}
