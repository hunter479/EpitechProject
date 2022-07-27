/*
** EPITECH PROJECT, 2019
** menger
** File description:
** day02
*/

#include <stdlib.h>
#include "menger.h"

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    for (int i = 0; av[1][i]; i++) {
        if (av[1][i] >= '0' && av[1][i] <= '9');
        else
            return (84);
    }
    for (int i = 0; av[2][i]; i++) {
        if (av[2][i] >= '0' && av[2][i] <= '9');
        else
            return (84);
    }
    if (check(my_getnbr(av[1]), my_getnbr(av[2])) == 84)
        return (84);
    menger(my_getnbr(av[1]), my_getnbr(av[2]), 0, 0);
    return (0);
}
