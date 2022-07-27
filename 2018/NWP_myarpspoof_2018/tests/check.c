/*
** EPITECH PROJECT, 2019
** NWP_myarpspoof_2018
** File description:
** check
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "myserver.h"

Test(check, str_to_tab)
{
    char **tab = str_to_tab("Bonjour, Hello", ',');

    cr_assert_str_eq(tab[0], "Bonjour");
    cr_assert_str_eq(tab[1], " Hello");
    cr_assert(str_to_tab(NULL, '\n') == NULL);
}

Test(check, hexdup, .init = cr_redirect_stdout)
{
    unsigned char *mac = (unsigned char *)strdup("azertyu");

    hexdup(mac, strlen((const char *)mac));
    fflush(NULL);
    cr_assert_stdout_eq_str("61 7a 65 72 74 79 75\n");
}
