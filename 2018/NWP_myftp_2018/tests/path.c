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


Test(pwd_command, path, .init = cr_redirect_stdout)
{
    server_t serv;
    char tab[50];

    serv.data.fd = 1;
    serv.user_log = 1;
    pwd_command(NULL, &serv);
    sprintf(tab, "257 \"%s\"\r\n", get_current_dir_name());
    cr_assert_stdout_eq_str(tab);
    fflush(stdout);
}

Test(cdup_command, path, .init = cr_redirect_stdout)
{
    server_t serv;

    serv.data.fd = 1;
    serv.user_log = 1;
    cdup_command(NULL, &serv);
    cr_assert_stdout_eq_str("250 Directory successfully changed.\r\n");
    fflush(stdout);
}

Test(cdup_command1, path, .init = cr_redirect_stdout)
{
    server_t serv;
    char *tab[3];

    tab[0] = "CWD";
    tab[1] = ".";
    serv.data.fd = 1;
    serv.user_log = 1;
    cwd_command(tab, &serv);
    cr_assert_stdout_eq_str(rfc_250);
    fflush(stdout);
}