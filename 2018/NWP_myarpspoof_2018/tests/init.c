/*
** EPITECH PROJECT, 2019
** NWP_myarpspoof_2018
** File description:
** init
*/

#include <criterion/criterion.h>
#include "myserver.h"

void init_package(my_arsp_t *serv, const int opcode);

Test(init, init_package)
{
    my_arsp_t serv;

    serv.buffer = malloc(sizeof(char) * IP_MAXPACKET);
    serv.dest_ip = strdup("192.168.1.1");
    serv.dest_mac = NULL;
    serv.source_ip = strdup("192.168.1.1");
    serv.source_mac = strdup("ff:ff:ff:ff:ff:ff");
    init_package(&serv, ARPOP_REPLY);
    cr_assert(((arphdr_t)
    (serv.buffer + sizeof(ethhdr)))->ar_op == htons(ARPOP_REPLY));
}