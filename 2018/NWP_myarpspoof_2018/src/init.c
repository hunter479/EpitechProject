/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** init
*/

#include "myserver.h"

int set_sock(const int flag)
{
    int domain = flag == 1 ? AF_INET : PF_PACKET;
    int type = flag == 1 ? SOCK_STREAM : SOCK_RAW;
    int protocol = flag == 1 ? IPPROTO_IP : htons(ETH_P_ALL);
    int fd = 0;

    if ((fd = socket(domain, type, protocol)) < 0) {
        perror("socket");
        return (-1);
    }
    return (fd);
}

int init_sock(const char *interface, const int flag)
{
    int fd = 0;
    const int len = strnlen(interface, 16);

    if (len == 16) {
        fprintf(stderr, "Too long iface name");
        return (-1);
    }
    fd = set_sock(flag);
    if (flag == 1)
        return (fd);
    if (setsockopt(fd, SOL_SOCKET, SO_BINDTODEVICE, interface, len) < 0) {
        perror("setsock");
        return (-1);
    }
    return (fd);
}

void init_var(my_arsp_t *serv)
{
    serv->buffer = (uint8_t *)malloc(IP_MAXPACKET);
    serv->source_ip = NULL;
    serv->source_mac = NULL;
    serv->dest_ip = NULL;
    serv->dest_mac = NULL;
    serv->raw_sock = 0;
    serv->printBroadcast = -1;
    serv->printSpoof = NULL;
}

void init_struct(my_arsp_t *serv)
{
    int flag = 0;

    if (serv->printBroadcast == 1 || serv->printSpoof != NULL) {
        flag = 1;
    }
    if ((serv->raw_sock = init_sock(serv->interface, flag)) == -1) {
        dprintf(2, "Fail to init socket\n");
        exit(84);
    }
    if ((serv->source_mac = get_mac_host(serv->interface,
    serv->raw_sock)) == NULL) {
        dprintf(2, "Fail to get mac Addresse");
        exit(84);
    }
}