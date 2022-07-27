/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** main
*/

#include "myserver.h"

void free_struct(my_arsp_t *serv)
{
    free(serv->buffer);
    serv->dest_ip != NULL ? free(serv->dest_ip) : (void)serv->dest_ip;
    serv->dest_mac != NULL ? free(serv->dest_mac) : (void)serv->dest_mac;
    serv->source_ip != NULL ? free(serv->source_ip) : (void)serv->source_ip;
    serv->source_mac != NULL ? free(serv->source_mac) : (void)serv->source_mac;
    serv->interface != NULL ? free(serv->interface) : (void)serv->interface;
    serv->printSpoof != NULL ? free(serv->printSpoof) : (void)serv->printSpoof;
}

int my_arsp(my_arsp_t *serv)
{
    init_package(serv, serv->printSpoof == NULL ? ARPOP_REQUEST : ARPOP_REPLY);
    if (serv->printBroadcast == -1 && serv->printSpoof == NULL) {
        send_package(serv);
        recev_from_serv(serv);
    } else
        hexdup(serv->buffer, sizeof(ethhdr) + sizeof(my_arphdr_s));
    free_struct(serv);
    return (0);
}

int main(int ac, char **av)
{
    my_arsp_t serv;

    if (parse_option(&serv, ac, av) == -1)
        return (return_usage(84));
    init_struct(&serv);
    return (my_arsp(&serv));
}