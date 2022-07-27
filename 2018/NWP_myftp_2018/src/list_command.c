/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** list_command
*/

#include <sys/time.h>
#include <sys/types.h>
#include "server.h"

static int list_dir_content(sock_t data, char *tmp)
{
    int save = dup(1);
    char *cmd = malloc(sizeof(char) * (18 + strlen(tmp)));
    int ret = 0;

    dup2(data.fd, 1);
    sprintf(cmd, "/usr/bin/ls -l %s", tmp);
    ret = system(cmd);
    free(cmd);
    dup2(save, 1);
    close(save);
    return (ret);
}

int mode_check(server_t *serv)
{
    if (is_co(serv, 1) == 1)
        return (1);
    if (serv->mode == NEUTRAL) {
        send_rcode(serv->data.fd, rfc_425);
        return (1);
    }
    return (0);
}

void list_command(char **tab, server_t *serv)
{
    int ret = 0;

    if (mode_check(serv) == 1)
        return;
    send_rcode(serv->data.fd, rfc_150);
    if (tab[1] == NULL)
        ret = list_dir_content(serv->transfer_data, ".");
    else
        ret = list_dir_content(serv->transfer_data, tab[1]);
    if (ret == 0)
        send_rcode(serv->data.fd, rfc_226);
    else
        send_rcode(serv->data.fd, rfc_450);
    serv->mode = NEUTRAL;
    close(serv->transfer_data.fd);
}
