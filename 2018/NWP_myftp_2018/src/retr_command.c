/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** retr_command
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "server.h"

int read_file_content(sock_t data, const char *file)
{
    int save = dup(1);
    char *cmd = malloc(sizeof(char) * (13 + strlen(file)));
    int ret = 0;

    dup2(data.fd, 1);
    sprintf(cmd, "/bin/cat %s", file);
    ret = system(cmd);
    free(cmd);
    dup2(save, 1);
    close(save);
    return (ret);
}

void retr_command(char **tab, server_t *serv)
{
    if (mode_check(serv) == 1)
        return;
    if (tab[1] == NULL) {
        send_rcode(serv->data.fd, "550 Permission denied.\r\n");
        return;
    }
    send_rcode(serv->data.fd, rfc_150);
    if (read_file_content(serv->transfer_data, tab[1]) != 0) {
        send_rcode(serv->data.fd, rfc_450);
    } else
        send_rcode(serv->data.fd, rfc_226);
    serv->mode = NEUTRAL;
    close(serv->transfer_data.fd);
}