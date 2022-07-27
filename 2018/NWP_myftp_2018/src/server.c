/*
** EPITECH PROJECT, 2019
** NWP
** File description:
** server
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include "server.h"

int server_launch(int port, char *path)
{
    server_t server;
    command_t *list = init_command_list();

    if (init_server(&server, port, path))
        return (84);
    if (bind_socket(&(server.control)) != 0) {
        close(server.control.fd);
        perror("server_launch <bind_socket>");
        return (84);
    }
    if (listen(server.control.fd, 11) < 0) {
        close(server.control.fd);
        perror("server_launch <listen>");
        return (84);
    }
    while (allow_connection(&server, list) == 0);
    close(server.control.fd);
    return (0);
}