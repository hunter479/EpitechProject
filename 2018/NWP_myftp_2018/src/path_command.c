/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** path_command
*/

#include "server.h"

void pwd_command(char **tab, server_t *serv)
{
    char *tmp = NULL;

    (void)tab;
    if (is_co(serv, 1) == 1)
        return;
    tmp = get_current_dir_name();
    if (tmp == NULL) {
        perror(tmp);
        send_rcode(serv->data.fd, rfc_550);
        return;
    }
    dprintf(serv->data.fd, rfc_257, tmp);
    free(tmp);
}

void cdup_command(char **tab, server_t *serv)
{
    (void)tab;
    if (is_co(serv, 1) == 1)
        return;
    if (chdir("..") == -1) {
        perror("..");
        send_rcode(serv->data.fd, rfc_550);
        return;
    }
    send_rcode(serv->data.fd, "250 Directory successfully changed.\r\n");
}

void cwd_command(char **tab, server_t *serv)
{
    if (is_co(serv, 1) == 1)
        return;
    if (!tab || tab[1] == NULL || chdir(tab[1]) == -1) {
        perror(tab != NULL ? tab[1] : "");
        send_rcode(serv->data.fd, rfc_550);
        return;
    }
    send_rcode(serv->data.fd, rfc_250);
}