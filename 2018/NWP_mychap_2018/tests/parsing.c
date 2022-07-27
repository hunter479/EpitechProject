/*
** EPITECH PROJECT, 2019
** NWP_mychap_2018
** File description:
** parsing
*/

#include <criterion/criterion.h>
#include "myserver.h"

Test(parsing, parse_option)
{
    char *tab[9];
    mychap_t serv;

    tab[0] = "./client";
    tab[1] = "-t";
    tab[2] = "127.0.0.1";
    tab[3] = "-p";
    tab[4] = "4242";
    tab[5] = NULL;
    cr_assert(parse_option(&serv, 5, tab) == 1);
}

Test(parsing, parse_option2)
{
    char *tab[9];
    mychap_t serv;

    tab[0] = "./client";
    tab[1] = "-t";
    tab[2] = "localhost";
    tab[3] = "-p";
    tab[4] = "4242";
    tab[5] = "-P";
    tab[6] = "epitech42";
    tab[7] = NULL;
    cr_assert(parse_option(&serv, 7, tab) == 0);
}
