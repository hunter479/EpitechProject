/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** tests1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "myserver.h"

Test(tools, return_usage)
{
    cr_assert_eq(return_usage(2), 2);
}

Test(tools, print_mac, .init = cr_redirect_stdout)
{
    char *mac = strdup("azertyu");

    print_mac(mac);
    fflush(NULL);
    cr_assert_stdout_eq_str("61:7A:65:72:74:79");
}

Test(tools, getmac)
{
    char *mac = get_mac((unsigned char *)("61:7A:65:72:74:79"));

    cr_assert_str_eq("azerty", (const char *)mac);
}

Test(get, get_mac)
{
    unsigned char *hex = (unsigned char *)strdup("61:7A:65:72:74:79");
    char *mac = get_mac(hex);

    cr_assert(mac != NULL);
}