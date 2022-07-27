/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** tests1
*/

#include <criterion/criterion.h>
#include "myserver.h"

Test(check, sha)
{
    u_int8_t *hash = do_sha(strdup("123456789"), strdup("epitech42"));

    cr_assert(strlen((const char *)hash) == 64);
}

Test(tools, do_package)
{
    mychap_t serv;

    serv.dest = init_addr(4242, "127.0.0.1");
    serv.src = init_addr(rand() % 65535 + 1000, "127.0.0.1");
    serv.buffer = malloc(IP_MAXPACKET);
    do_package(&serv, "client hello");
    cr_assert_str_eq((const char *)serv.data, "client hello");
}
