/*
** EPITECH PROJECT, 2019
** NWP_mychap_2018
** File description:
** tools
*/

#include "myserver.h"

int return_usage(int value)
{
    fprintf(stderr, "Usage:\n./client -t [Target] -p [Port] -P [Password]\n");
    return (value);
}

void do_package(mychap_t *serv, const char *msg)
{
    memset(serv->buffer, 0, IP_MAXPACKET);
    init_package(serv, strlen(msg));
    serv->data = write_data(serv->data, msg);
}

int package_procedure(mychap_t *serv, const char *str)
{
    do_package(serv, str);
    send_package(serv);
    return (recev_from_serv(serv));
}
