/*
** EPITECH PROJECT, 2019
** NWP_my_arsp_2018
** File description:
** struct_iphdr
*/

#include <time.h>
#include "myserver.h"

void init_arp(my_arsp_t *serv, const int opcode)
{
    arphdr_t arp = (arphdr_t)(serv->buffer + 14);

    arp->ar_hrd = htons(1);
    arp->ar_pro = htons(ETH_P_IP);
    arp->ar_hln = 6;
    arp->ar_pln = 4;
    arp->ar_op = htons(opcode);

    memcpy(&arp->__ar_sha, serv->source_mac, 6 * sizeof(uint8_t));
    inet_pton(AF_INET, serv->source_ip, &arp->__ar_sip);
    if (serv->dest_mac == NULL)
        memset(&arp->__ar_tha, 0xff, 6 * sizeof(uint8_t));
    else
        memcpy(&arp->__ar_tha, serv->dest_mac, 6 * sizeof(uint8_t));
    inet_pton (AF_INET, serv->dest_ip, &arp->__ar_tip);
    serv->len_buffer += (sizeof(my_arphdr_s));
}

void init_eth(my_arsp_t *serv)
{
    memcpy((serv->buffer + 6 * sizeof(uint8_t)),
    serv->source_mac, 6 * sizeof(uint8_t));
    if (serv->dest_mac == NULL)
        memset(serv->buffer, 0xff, 6 * sizeof(uint8_t));
    else
        memcpy(serv->buffer, serv->dest_mac, 6 * sizeof(uint8_t));
    serv->buffer[12] = ETH_P_ARP / 256;
    serv->buffer[13] = ETH_P_ARP % 256;
    serv->len_buffer += sizeof(ethhdr);
}

void init_package(my_arsp_t *serv, const int opcode)
{
    serv->len_buffer = 0;
    serv->buffer = memset(serv->buffer, 0, IP_MAXPACKET);
    init_eth(serv);
    init_arp(serv, opcode);
}