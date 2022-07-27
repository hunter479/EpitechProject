/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** command
*/

#include "server.h"

void launch_command(char **tab, server_t *serv, command_t *command)
{
    int i = 0;

    if (!tab)
        return;
    while (command[i].name) {
        if (strncmp(tab[0], command[i].name, strlen(command[i].name)) == 0) {
            (command[i].command)(tab, serv);
            return;
        }
        i++;
    }
    send_rcode(serv->data.fd, rfc_500);
    for (int i = 0; tab[i]; free(tab[i]), i++);
}

void do_command(server_t *serv, command_t *list)
{
    char *msg = NULL;

    serv->state = 1;
    while (serv->state == 1) {
        if (do_select(&(serv->data), 30, 0) != 0) {
            msg = get_next_line(serv->data.fd);
            launch_command(str_to_tab(msg, ' '), serv, list);
            if (msg)
                free(msg);
        } else {
            serv->state = 0;
            send_rcode(serv->data.fd, "221 Timeout\r\n");
            close(serv->data.fd);
        }
    }
}

void noop_command(char **tab, server_t *serv)
{
    (void)tab;
    send_rcode(serv->data.fd, rfc_200);
}

void help_command(char **tab, server_t *serv)
{
    (void)tab;
    send_rcode(serv->data.fd, rfc_214);
}