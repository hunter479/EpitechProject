/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** tests1
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/server.h"

Test(check, str_to_tab)
{
    char **tab = str_to_tab("Bonjour,Hello", ',');

    cr_assert_str_eq(tab[0], "Bonjour");
    cr_assert_str_eq(tab[1], "Hello");
    cr_assert(str_to_tab(NULL, '\n') == NULL);
}

Test(check_sock, accept_sock)
{
    sock_t data = init_socket(4242);

    data.fd = 1;
    cr_assert(accept_sock(&data, 1) == 1);
}

Test(gnl, reading)
{
    int fd =  open("./tests/sample", O_RDONLY);
    char *tmp = NULL;

    tmp = get_next_line(fd);
    cr_assert_str_eq(tmp, "A");
    close(fd);
}

Test(noop, command,  .init = cr_redirect_stdout)
{
    server_t data;

    data.data.fd = 1;
    noop_command(NULL, &data);
    cr_assert_stdout_eq_str(rfc_200);
    fflush(stdout);
}

Test(help, command,  .init = cr_redirect_stdout)
{
    server_t data;

    data.data.fd = 1;
    help_command(NULL, &data);
    cr_assert_stdout_eq_str(rfc_214);
    fflush(stdout);
}
