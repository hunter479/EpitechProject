/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** transfer
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/server.h"

Test(port1, transfer, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[0] = "PORT";
    tab[1] = "127,0.0.1";
    serv.data.fd = 1;
    serv.user_log = 1;
    serv.mode = PASV;
    port_command(tab, &serv);
    cr_assert_stdout_eq_str("500 Illegal PORT command.\r\n");
    fflush(stdout);
}

Test(port2, transfer, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[0] = "PORT";
    tab[1] = "127,0,0,1,10000,23";
    serv.data.fd = 1;
    serv.user_log = 1;
    serv.mode = PASV;
    port_command(tab, &serv);
    cr_assert_stdout_eq_str("500 Illegal PORT command.\r\n");
    fflush(stdout);
}

Test(port3, transfer, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[0] = "PORT";
    tab[1] = "127,0,0,1,42,42";
    serv.data.fd = 1;
    serv.user_log = 1;
    serv.mode = PASV;
    port_command(tab, &serv);
    cr_assert_stdout_eq_str("425 Cannot Connect To The Port.\r\n");
    fflush(stdout);
}