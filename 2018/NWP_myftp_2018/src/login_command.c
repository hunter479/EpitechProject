/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** login_command
*/

#include "server.h"

void user_command(char **tab, server_t *serv)
{
    if (is_co(serv, 0) == 1)
        return;
    send_rcode(serv->data.fd, rfc_331);
    if (tab[1])
        serv->user = strdup(tab[1]);
}

void pass_command(char **tab, server_t *serv)
{
    if (is_co(serv, 0) == 1)
        return;
    if (serv->user == NULL) {
        send_rcode(serv->data.fd, rfc_503);
        return;
    }
    if (tab[1] == NULL || strcmp(tab[1], "\0") != 0 ||
    strcmp(serv->user, "Anonymous") != 0) {
        free(serv->user);
        serv->user = NULL;
        send_rcode(serv->data.fd, "530 Invalide password or username\r\n");
        return;
    } else {
        send_rcode(serv->data.fd, rfc_230);
        serv->user_log = 1;
    }
}

void quit_command(char **tab, server_t *serv)
{
    (void)(tab);
    send_rcode(serv->data.fd, rfc_221);
    serv->state = 0;
    close(serv->data.fd);
}
