/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** client
*/

#include <signal.h>
#include <sys/time.h>
#include "server.h"

int is_co(server_t *serv, const int opt)
{
    if (opt == 1) {
        if (serv->user_log == 0) {
            send_rcode(serv->data.fd, rfc_530);
            return (1);
        }
    } else {
        if (serv->user_log == 1) {
            send_rcode(serv->data.fd, rfc_230);
            return (1);
        }
    }
    return (0);
}

int allow_connection(server_t *serv, command_t *list)
{
    if (do_select(&(serv->control), 1, 0)) {
        create_client(serv, list);
    }
    return (0);
}

int create_client(server_t *serv, command_t *list)
{
    pid_t id = 0;

    if ((id = fork()) == 0) {
        if (accept_sock(&(serv->data), serv->control.fd) == 0) {
            send_rcode(serv->data.fd, rfc_220);
            do_command(serv, list);
        }
        exit(0);
    } else
        usleep(1000);
    return (0);
}
