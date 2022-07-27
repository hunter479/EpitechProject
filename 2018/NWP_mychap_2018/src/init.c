/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** init
*/

#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "myserver.h"

int init_sock(void)
{
    int fd = 0;
    int one = 1;

    if ((fd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP)) < 0) {
        perror("socket");
        return (-1);
    }
    if (setsockopt(fd, IPPROTO_IP, IP_HDRINCL, &one, sizeof(one)) == -1) {
        perror("setsock");
        return (-1);
    }
    return (fd);
}

struct sockaddr_in init_addr(const int port, const char *addr)
{
    struct sockaddr_in sock;

    memset(&sock, 0, sizeof(struct sockaddr));
    sock.sin_family = AF_INET;
    sock.sin_port = htons(port);
    if (strcmp(addr, "0") == 0)
        sock.sin_addr.s_addr = 0;
    else
        sock.sin_addr.s_addr = inet_addr(addr);
    return (sock);
}

void init_var(mychap_t *serv)
{
    serv->buffer = (uint8_t *)malloc(IP_MAXPACKET);
    serv->data = NULL;
    serv->password = NULL;
    serv->port = -1;
    serv->target = NULL;
    serv->raw_sock = 0;
    serv->answer = NULL;
    serv->hash = NULL;
}

void init_struct(mychap_t *serv)
{
    srand(time(0));
    serv->dest = init_addr(serv->port, serv->target);
    serv->src = init_addr(rand() % 65535 + 1000, "0");
    if ((serv->raw_sock = init_sock()) == -1) {
        dprintf(2, "Fail to init socket\n");
        exit(84);
    }
}