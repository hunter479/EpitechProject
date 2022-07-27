/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** pasv
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "server.h"

void closefds(server_t *serv)
{
    if (serv->transfer_data.fd != -1) {
        close(serv->transfer_data.fd);
        serv->transfer_data.fd = -1;
    }
    if (serv->transfer_sock.fd != -1) {
        close(serv->transfer_sock.fd);
        serv->transfer_sock.fd = -1;
    }
}

static int pasv_proceed(sock_t *data)
{
    if (bind_socket(data) != 0) {
        perror("pasv_command <bind_socket>");
        return (1);
    }
    if (listen(data->fd, 2) < 0) {
        perror("pasv_command <listen>");
        close(data->fd);
        return (1);
    }
    return (0);
}

static void pasv_activ(server_t *serv, sock_t data)
{
    char *addr_f = get_sock_ip(serv->data, data);
    int port = get_sock_port(data);

    dprintf(serv->data.fd, rfc_227, addr_f, port / 256, port % 256);
    serv->mode = PASV;
    serv->transfer_sock = data;
    serv->transfer_data.addrlen = sizeof(struct sockaddr);
    memset(&(serv->transfer_data.addr), 0, sizeof(struct sockaddr));
    if (do_select(&(serv->transfer_sock), 30, 0) != 0) {
        accept_sock(&(serv->transfer_data), data.fd);
    } else {
        send_rcode(serv->data.fd, "425 Failed to establish connection.\r\n");
        close(serv->transfer_sock.fd);
        serv->mode = NEUTRAL;
    }
}

void pasv_command(char **tab, server_t *serv)
{
    sock_t data;

    (void)(tab);
    if (is_co(serv, 1) == 1)
        return;
    closefds(serv);
    data = init_socket(0);
    data.addr.sin_addr.s_addr = inet_addr(inet_ntoa(serv->data.addr.sin_addr));
    if (pasv_proceed(&data) == 1) {
        send_rcode(serv->data.fd, rfc_421);
        return;
    }
    pasv_activ(serv, data);
}
