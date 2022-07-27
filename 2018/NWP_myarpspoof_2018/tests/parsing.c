/*
** EPITECH PROJECT, 2019
** NWP_my_arsp_2018
** File description:
** parsing
*/

#include <criterion/criterion.h>
#include "myserver.h"

Test(parsing, parse_option)
{
    char **tab = malloc(sizeof(char *) * (4 + 1));
    my_arsp_t serv;

    tab[0] = strdup("./myARPspoof");
    tab[1] = strdup("192.168.1.1");
    tab[2] = strdup("192.168.1.14");
    tab[3] = NULL;
    cr_assert(parse_option(&serv, 3, tab) == -1);
}

Test(parsing, parse_option2)
{
    char **tab = malloc(sizeof(char *) * 9);
    my_arsp_t serv;

    tab[0] = strdup("./myARPspoof");
    tab[1] = strdup("192.168.1.1");
    tab[2] = strdup("192.168.1.14");
    tab[3] = strdup("enp0s31f6");
    tab[4] = strdup("--printBroadcast");
    tab[5] = strdup("--printSpoof");
    tab[6] = strdup("01:23:45:67:8A");
    tab[7] = NULL;
    cr_assert(parse_option(&serv, 7, tab) == -1);
    cr_assert(serv.printBroadcast == 1);
    cr_assert_str_eq(((const char *)serv.printSpoof), "01:23:45:67:8A");
}

Test(parsing, parse_option3)
{
    char **tab = malloc(sizeof(char *) * 9);
    my_arsp_t serv;

    tab[0] = strdup("./myARPspoof");
    tab[1] = strdup("192.168.1.1");
    tab[2] = strdup("192.168.1.14");
    tab[3] = strdup("enp0s31f6");
    tab[4] = strdup("--printSpoof");
    tab[5] = strdup("01:23:45:67:8A");
    tab[6] = NULL;
    cr_assert(parse_option(&serv, 6, tab) == 0);
    cr_assert_str_eq(serv.dest_ip, "192.168.1.14");
    cr_assert_str_eq(serv.source_ip, "192.168.1.1");
    cr_assert_str_eq(serv.interface, "enp0s31f6");
    cr_assert_str_eq(((const char *)serv.printSpoof), "01:23:45:67:8A");
}

Test(parsing, parse_optio43)
{
    char **tab = malloc(sizeof(char *) * 9);
    my_arsp_t serv;

    tab[0] = strdup("./myARPspoof");
    tab[1] = strdup("192.168.1.1");
    tab[2] = strdup("192.168.1.14");
    tab[3] = strdup("enp0s31f6");
    tab[4] = strdup("--printBroadcast");
    tab[5] = NULL;
    cr_assert(parse_option(&serv, 5, tab) == 0);
    cr_assert_str_eq(serv.dest_ip, "192.168.1.14");
    cr_assert_str_eq(serv.source_ip, "192.168.1.1");
    cr_assert_str_eq(serv.interface, "enp0s31f6");
    cr_assert(serv.printBroadcast == 1);
}
