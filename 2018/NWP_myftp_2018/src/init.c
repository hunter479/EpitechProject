/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** init
*/

#include <stdlib.h>
#include <dirent.h>
#include "server.h"

sock_t init_socket(int port)
{
    sock_t sock;

    sock.addrlen = sizeof(struct sockaddr);
    sock.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (!sock.fd) {
        perror("init_sock");
        exit(84);
    }
    memset(&sock.addr, 0, sizeof(struct sockaddr));
    sock.addr.sin_family = AF_INET;
    sock.addr.sin_addr.s_addr = INADDR_ANY;
    sock.addr.sin_port = htons(port);
    return (sock);
}

int bind_socket(sock_t *sock)
{
    if (bind(sock->fd, (struct sockaddr *)&sock->addr,
    sizeof(struct sockaddr_in)) < 0) {
        perror("<bind_socket>");
        return (1);
    }
    return (0);
}

int init_var_struct(server_t *serv, char *path)
{
    serv->user_log = 0;
    serv->state = 0;
    serv->transfer_data.fd = -1;
    serv->transfer_sock.fd = -1;
    serv->mode = NEUTRAL;
    serv->user = NULL;
    if (chdir(path) == -1) {
        perror(path);
        return (1);
    }
    return (0);
}

int init_server(server_t *server, int port, char *path)
{
    if (init_var_struct(server, path) == 1)
        return (1);
    server->control = init_socket(port);
    server->data.addrlen = sizeof(struct sockaddr);
    memset(&(server->data.addr), 0, sizeof(struct sockaddr));
    return (0);
}
