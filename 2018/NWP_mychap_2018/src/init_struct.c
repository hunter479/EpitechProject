/*
** EPITECH PROJECT, 2019
** NWP_mychap_2018
** File description:
** struct_iphdr
*/

#include <time.h>
#include "myserver.h"

static unsigned short csum(unsigned short *buf, int nwords)
{
    unsigned long sum;

    for (sum = 0; nwords > 0; nwords--)
        sum += *buf++;
    sum = (sum >> 16) + (sum &0xffff);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

void init_iphdr(mychap_t *chap, const int size)
{
    iphdr_t ip = (iphdr_t)chap->buffer;

    ip->version = 4;
    ip->ihl = 5;
    ip->tos = 0;
    ip->tot_len = sizeof(iphdr) + sizeof(udphdr) + size;
    ip->id = rand() * 0xFFFFF;
    ip->frag_off = 0x40;
    ip->ttl = 64;
    ip->protocol = IPPROTO_UDP;
    ip->check = 0;
    ip->saddr = chap->src.sin_addr.s_addr;
    ip->daddr = chap->dest.sin_addr.s_addr;
    ip->check = csum((unsigned short *)chap->buffer, ip->tot_len);
    chap->len += sizeof(iphdr);
}

void init_udphdr(mychap_t *chap, const int size)
{
    udphdr_t udp = (udphdr_t)(chap->buffer + sizeof(iphdr));
    uint16_t length = 8 + size;

    udp->source = chap->src.sin_port;
    udp->dest = chap->dest.sin_port;
    udp->len = htons(length);
    udp->check = 0;
    chap->len += sizeof(udphdr);
}

uint8_t *write_data(uint8_t *data, const char *str)
{
    data = (uint8_t *)strcpy((char *)data, str);
    return (data);
}

void init_package(mychap_t *serv, const int size)
{
    srand(time(0));
    serv->len = 0;
    serv->buffer = memset(serv->buffer, 0, IP_MAXPACKET);
    init_udphdr(serv, size);
    init_iphdr(serv, size);
    serv->len += size;
    serv->data = serv->buffer + sizeof(iphdr) + sizeof(udphdr);
}