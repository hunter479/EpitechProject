/*
** EPITECH PROJECT, 2019
** NWP_mychap_2018
** File description:
** check_init
*/

#include <criterion/criterion.h>
#include "myserver.h"

Test(check_init, init_var)
{
    mychap_t serv;

    init_var(&serv);
    cr_assert(serv.hash == NULL);
}

Test(check_init, init_addr)
{
    struct sockaddr_in data;

    data = init_addr(4242, "127.0.0.1");
    cr_assert(inet_ntoa(data.sin_addr));
}

Test(check_init, init_sock)
{
    cr_assert(init_sock() == -1);
}