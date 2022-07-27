/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** serv
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/server.h"

Test(retr_command, serv, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[0] = "RETR";
    tab[1] = "sample";
    serv.mode = NEUTRAL;
    serv.user_log = 1;
    serv.data.fd = 1;
    retr_command(tab, &serv);
    cr_assert_stdout_eq_str(rfc_425);
    fflush(stdout);
}

Test(retr_command2, serv, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[0] = "RETR";
    tab[1] = "./tests/sample";
    serv.mode = PASV;
    serv.user_log = 1;
    serv.data.fd = 1;
    retr_command(tab, &serv);
    cr_assert_stdout_eq_str("150 File status okay; about to open data \
connection.\r\nA\nB\nC\nD\nE\n226 Closing data connection.\r\n");
    fflush(stdout);
}

Test(retr_command3, serv, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[0] = "RETR";
    tab[1] = NULL;
    serv.mode = PASV;
    serv.user_log = 1;
    serv.data.fd = 1;
    retr_command(tab, &serv);
    cr_assert_stdout_eq_str("550 Permission denied.\r\n");
    fflush(stdout);
}

Test(retr_command4, serv, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[0] = "RETR";
    tab[1] = "a";
    serv.mode = PASV;
    serv.user_log = 1;
    serv.data.fd = 1;
    retr_command(tab, &serv);
    cr_assert_stdout_eq_str("150 File status okay; about to open data \
connection.\r\n450 Requested file action not taken.\r\n");
    fflush(stdout);
}
