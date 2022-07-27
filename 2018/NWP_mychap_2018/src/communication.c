/*
** EPITECH PROJECT, 2019
** NWP_mychap_2018
** File description:
** Communcation
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include "myserver.h"

static int is_for_me(udphdr_t rev_udp, mychap_t *serv)
{
    if (rev_udp->source == serv->dest.sin_port &&
    rev_udp->dest == serv->src.sin_port)
        return (0);
    else
        return (1);
}

int recev_from_serv(mychap_t *serv)
{
    char msg[IP_MAXPACKET];
    int n = -42;
    time_t timer = time(NULL);

    while (n != 0) {
        if ((time(NULL) - timer) >= 5) {
            printf("Session Timeout\n");
            return (1);
        }
        memset(msg, 0, IP_MAXPACKET);
        if ((n = recv(serv->raw_sock, msg, IP_MAXPACKET, 0)) == -1) {
            perror("recv");
            return (1);
        }
        if (is_for_me((udphdr_t)(msg + sizeof(iphdr)), serv) == 0)
            break;
    }
    serv->answer = (uint8_t *)strdup((msg + sizeof(iphdr) + sizeof(udphdr)));
    return (0);
}

void send_package(mychap_t *serv)
{
    int send_len = sendto(serv->raw_sock, serv->buffer, serv->len, 0,
    (struct sockaddr *)&(serv->dest), sizeof(struct sockaddr_in));

    if (send_len < 0) {
        perror("sendto");
        exit(84);
    }
}
