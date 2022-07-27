/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** stor_command
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "server.h"

int create_file(server_t *serv, char *file)
{
    int flag = O_RDWR | O_CREAT;
    int fd =  open(file, flag, 0644);
    char *tmp = NULL;

    if (!fd) {
        perror(file);
        return (-1);
    }
    tmp = get_next_line(serv->transfer_data.fd);
    while (tmp) {
        dprintf(fd, tmp);
        free(tmp);
        tmp = get_next_line(serv->transfer_data.fd);
        if (tmp != NULL)
            dprintf(fd, "\n");
    }
    close(fd);
    return (0);
}

void stor_command(char **tab, server_t *serv)
{
    if (mode_check(serv) == 1)
        return;
    if (tab[1] == NULL) {
        send_rcode(serv->data.fd, rfc_550);
        return;
    }
    send_rcode(serv->data.fd, rfc_150);
    if (create_file(serv, tab[1]) == -1)
        send_rcode(serv->data.fd, rfc_450);
    else
        send_rcode(serv->data.fd, rfc_226);
    serv->mode = NEUTRAL;
    close(serv->transfer_data.fd);
}
