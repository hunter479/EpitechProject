/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** init
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/server.h"

Test(init_data, init_socket)
{
    sock_t data = init_socket(4242);

    cr_assert(data.fd != -1);
}

Test(init_server, init)
{
    server_t serv;

    cr_assert(init_server(&serv, 4242, ".") == 0);
    cr_assert(init_server(&serv, 4242, "ABC") == 1);
}

Test(parse_addr, parsing)
{
    int port1 = 0;
    int port2 = 0;
    char *addr = NULL;

    parse_addr("127,0,0,1,42,42", &addr, &port1, &port2);
    cr_assert(port1 == 42);
    cr_assert(port2 == 42);
    cr_assert_str_eq(addr, "127.0.0.1");
}

Test(init_var_struct, init)
{
    server_t serv;

    cr_assert(init_var_struct(&serv, ".") == 0);
    cr_assert(init_var_struct(&serv, "Toto") == 1);
}

Test(bind_socket, init)
{
    sock_t data;

    data.fd = 0;
    cr_assert(bind_socket(&data) == 1);
}