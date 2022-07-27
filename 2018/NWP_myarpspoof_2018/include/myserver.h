/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** server
*/

#ifndef MYSERVER_H_
    #define MYSERVER_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <time.h>
#include <sys/ioctl.h>
#include <net/if_arp.h>
#include <net/if.h>

typedef struct ethhdr ethhdr;
typedef struct my_arphdr_s my_arphdr_s;
typedef my_arphdr_s *arphdr_t;
typedef ethhdr *ethhdr_t;

struct my_arphdr_s
{
    unsigned short int ar_hrd;		/* Format of hardware address.  */
    unsigned short int ar_pro;		/* Format of protocol address.  */
    uint8_t ar_hln;		/* Length of hardware address.  */
    uint8_t ar_pln;		/* Length of protocol address.  */
    unsigned short int ar_op;		/* ARP opcode (command).  */

    uint8_t __ar_sha[ETH_ALEN];	/* Sender hardware address.  [ETH_ALEN]*/
    uint8_t __ar_sip[4];		/* Sender IP address.  [4]*/
    uint8_t __ar_tha[ETH_ALEN];	/* Target hardware address.  [ETH_ALEN]*/
    uint8_t __ar_tip[4];		/* Target IP address.  [4]*/
};

typedef struct my_arsp_s
{
    int printBroadcast;
    u_int8_t *printSpoof;

    char *source_ip;
    char *source_mac;
    char *dest_ip;
    char *dest_mac;
    char *interface;

    int raw_sock;
    uint8_t *buffer;
    int len_buffer;
} my_arsp_t;

int return_usage(int value);
void init_struct(my_arsp_t *serv);
void init_var(my_arsp_t *serv);
int parse_option(my_arsp_t *serv, int ac, char **av);
int recev_from_serv(my_arsp_t *serv);
void init_package(my_arsp_t *serv, const int opcode);
void send_package(my_arsp_t *serv);
void flood_it(my_arsp_t *serv);
void print_mac(const char *mac);
char *get_mac(unsigned char *mac);
void hexdup(const uint8_t *buffer, int size);
char **str_to_tab(char *str, const char c);
char *get_mac_host(const char *interface, const int sock);

#endif /* !MYSERVER_H_ */
