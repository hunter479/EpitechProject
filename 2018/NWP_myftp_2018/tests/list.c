/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** list
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/server.h"

Test(list_command, list, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[1] = NULL;
    serv.data.fd = 1;
    serv.transfer_data.fd = 2;
    serv.user_log = 1;
    serv.mode = PASV;
    list_command(tab, &serv);
    cr_assert_stdout_eq_str("150 File status okay; about to open data \
connection.\r\n226 Closing data connection.\r\n");
    fflush(stdout);
}

Test(list_command2, list, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[1] = "abc";
    serv.data.fd = 1;
    serv.transfer_data.fd = 2;
    serv.user_log = 1;
    serv.mode = PASV;
    list_command(tab, &serv);
    cr_assert_stdout_eq_str("150 File status okay; about to open data \
connection.\r\n450 Requested file action not taken.\r\n");
    fflush(stdout);
}
