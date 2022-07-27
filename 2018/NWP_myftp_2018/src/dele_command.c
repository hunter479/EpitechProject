/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** dele_command
*/

#include "server.h"

void dele_command(char **tab, server_t *serv)
{
    if (tab[1] == NULL) {
        send_rcode(serv->data.fd, rfc_501);
        return;
    }
    if (remove(tab[1]) != 0) {
        send_rcode(serv->data.fd, rfc_550);
        return;
    }
    send_rcode(serv->data.fd, rfc_250);
}