/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** tools
*/

#include <signal.h>
#include <sys/time.h>
#include "server.h"

int do_select(sock_t *serv, const int sec, const int usec)
{
    FD_ZERO(&(serv->slc.read_fds));
    FD_SET(serv->fd, &(serv->slc.read_fds));
    serv->slc.timeout.tv_sec = sec;
    serv->slc.timeout.tv_usec = usec;
    return (select(serv->fd + 1, &(serv->slc.read_fds), NULL,
    NULL, &(serv->slc.timeout)));
}

int accept_sock(sock_t *data, int fd)
{
    data->fd = accept(fd, (struct sockaddr *)&data->addr, &data->addrlen);
    if (data->fd < 0) {
        close(fd);
        perror("create_client <accept>");
        return (1);
    }
    return (0);
}

void send_rcode(const int fd, const char *rfc)
{
    if (!fd) {
        fprintf(stderr, "!fd\n");
        return;
    }
    write(fd, rfc, strlen(rfc));
}

char *get_sock_ip(sock_t serv, sock_t data)
{
    char *ret = malloc(sizeof(char) * 50);
    char **tmp = NULL;

    data.addr.sin_addr.s_addr = inet_addr(inet_ntoa(serv.addr.sin_addr));
    tmp = str_to_tab(inet_ntoa(data.addr.sin_addr), '.');
    sprintf(ret, "%s,%s,%s,%s", tmp[0], tmp[1], tmp[2], tmp[3]);
    return (ret);
}

int get_sock_port(sock_t data)
{
    struct sockaddr_in sin;
    socklen_t len = sizeof(sin);

    if (getsockname(data.fd, (struct sockaddr *)&sin, &len) != -1)
        return (ntohs(sin.sin_port));
    return (0);
}
