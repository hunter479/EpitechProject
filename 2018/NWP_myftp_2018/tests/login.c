/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** login
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/server.h"

Test(user, login, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[0] = "USER";
    tab[1] = "TOTO";
    serv.data.fd = 1;
    serv.user_log = 0;
    user_command(tab, &serv);
    cr_assert_stdout_eq_str(rfc_331);
    fflush(stdout);
}

Test(pass, login, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[1] = "";
    serv.user = NULL;
    serv.data.fd = 1;
    serv.user_log = 0;
    pass_command(tab, &serv);
    cr_assert_stdout_eq_str(rfc_503);
    fflush(stdout);
}

Test(pass1, login, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[1] = "a";
    serv.user = strdup("Anonymous");
    serv.data.fd = 1;
    serv.user_log = 0;
    pass_command(tab, &serv);
    cr_assert_stdout_eq_str("530 Invalide password or username\r\n");
    fflush(stdout);
}

Test(pass2, login, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[1] = "";
    serv.user = strdup("Anonymous");
    serv.data.fd = 1;
    serv.user_log = 0;
    pass_command(tab, &serv);
    cr_assert_stdout_eq_str(rfc_230);
    fflush(stdout);
}

Test(pass3, login, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[1] = "a";
    serv.user = strdup("Anonymous");
    serv.data.fd = 1;
    serv.user_log = 1;
    pass_command(tab, &serv);
    cr_assert_stdout_eq_str(rfc_230);
    fflush(stdout);
}
