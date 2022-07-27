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
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

typedef struct iphdr iphdr;
typedef struct udphdr udphdr;
typedef iphdr *iphdr_t;
typedef udphdr *udphdr_t;

typedef struct mychap_s
{
    uint8_t *buffer;
    uint8_t *data;
    struct sockaddr_in src;
    struct sockaddr_in dest;

    int raw_sock;
    char *target;
    int port;
    char *password;
    size_t len;
    uint8_t *answer;
    uint8_t *hash;
} mychap_t;

// Parse
int parse_option(mychap_t *serv, int ac, char **av);
uint8_t *write_data(uint8_t *data, const char *);

// Init
struct sockaddr_in init_addr(const int port, const char *target);
int init_sock(void);
void init_struct(mychap_t *serv);
void init_var(mychap_t *serv);
void init_package(mychap_t *serv, const int);

//Cryptage
uint8_t *do_sha(const char *answer, const char *password);

// Communication
int recev_from_serv(mychap_t *serv);
void send_package(mychap_t *serv);

//Tools
char *get_ip(const char *str);
char **str_to_tab(char *str, const char c);
int return_usage(int value);
int package_procedure(mychap_t *serv, const char *str);
void do_package(mychap_t *serv, const char *msg);

#endif /* !MYSERVER_H_ */
