/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** login2
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/server.h"

Test(quit_command, login, .init = cr_redirect_stdout)
{
    server_t serv;

    serv.data.fd = 1;
    quit_command(NULL, &serv);
    cr_assert_stdout_eq_str(rfc_221);
    fflush(stdout);
}
