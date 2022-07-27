/*
** EPITECH PROJECT, 2019
** NWP_my_arsp_2018
** File description:
** tools
*/

#include "myserver.h"

int return_usage(int value)
{
    fprintf(stderr, "Usage:\n./myarpspoof [source_ip] [dest_ip] [Option]");
    fprintf(stderr, " : --printBroadcast | --printSpoof [MAC addr]\n");
    return (value);
}

void print_mac(const char *mac)
{
    for (int i = 0; i < 6; i++) {
        fprintf(stdout, "%02X", (uint8_t)mac[i]);
        if (i < 5)
            fprintf(stdout, ":");
    }
}

void hexdup(const uint8_t *buffer, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%02x", buffer[i]);
        if (i + 1 < size)
            printf(" ");
    }
    printf("\n");
}

void flood_it(my_arsp_t *serv)
{
    time_t e = time(NULL);
    init_package(serv, ARPOP_REPLY);

    while (42) {
        if ((time(NULL) - e) >= 1) {
            send_package(serv);
            printf("Spoofed packet sent to '%s'\n", serv->dest_ip);
            e = time(NULL);
        }
    }
}