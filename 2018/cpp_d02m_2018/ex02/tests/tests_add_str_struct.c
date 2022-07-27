/*
** EPITECH PROJECT, 2019
** cpp_d01_2018
** File description:
** tests_function_name
*/

#include <criterion/criterion.h>

void    tab_to_2dtab(const int *tab, int lenght, int width, int ***res);

Test(add_str_struct, calcul)
{
    int tab[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int **to_2dtab;

    tab_to_2dtab(tab, 2, 2, &to_2dtab);
    cr_assert(to_2dtab[0][0] == 0);
}
