/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** pool 02
*/

#include <stdio.h>

int    my_getnbr(char const *str)
{
    int	i = 0;
    int	a = 0;
    int	s = 1;

    while (str[i] == '-' || str[i] == '+')
        s *= (str[i++] == '-') ? -1 : 1;
    while  (str[i] >= '0'  && str[i] <= '9')
        a = a * 10 + str[i++] - '0';
    return (a * s);
}

int    check(int size, int level)
{
    if (size <= 0)
        return (84);
    else if (level <= 0)
        return (84);
    if (size >= (level * level * level))
        return (0);
    return (84);
}

void    menger(int size, int level, int x, int y)
{
    int x_new = x;
    int y_new = y;

    if (level < 1 || size < 1 )
        return;
    printf("%03d %03d %03d\n",size / 3, x_new + size / 3, y_new + size / 3);
    while (x_new < size + x) {
        menger(size / 3, level - 1, x_new, y_new);
        y_new += size / 3;
        if (y_new >= size + y) {
            y_new = y;
            x_new += size / 3;
        }
        if (y_new == size / 3 + y && x_new == size / 3 + x)
            y_new += size / 3;
    }
}
