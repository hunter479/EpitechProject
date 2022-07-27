/*
** EPITECH PROJECT, 2019
** NWP_myarpspoof_2018
** File description:
** mac_tools
*/

#include "myserver.h"

static int hex_to_int(char c)
{
    int first = c / 16 - 3;
    int second = c % 16;
    int result = first * 10 + second;

    if (result > 9)
        result--;
    return (result);
}

static int hex_to_ascii(char c, char d)
{
    int high = hex_to_int(c) * 16;
    int low = hex_to_int(d);

    return (high + low);
}

char *get_mac(unsigned char *mac)
{
    char **tab = str_to_tab((char *)(mac), ':');
    char *str = malloc(sizeof(char) * strlen((char *)mac));
    char c = 0;

    memset(str, 0, sizeof(char) * strlen((char *)mac));
    for (int i = 0 ; tab[i] ; i++) {
        if (tab[i] != NULL) {
            c = hex_to_ascii(tab[i][0], tab[i][1]);
            str[i] = c;
        }
        free(tab[i]);
    }
    free(tab);
    return (str);
}

char *get_mac_host(const char *interface, const int sock)
{
    struct ifreq req;
    char *mac = NULL;

    memset(&req, 0, sizeof(req));
    strncpy(req.ifr_name, interface, IF_NAMESIZE - 1);
    if (ioctl(sock, SIOCGIFHWADDR, &req) < 0) {
        perror("ioctl");
        return (NULL);
    }
    mac = malloc(sizeof(char) * 7);
    memset(mac, 0, 7);
    for (size_t i = 0; i < 6; i++)
        mac[i] = req.ifr_hwaddr.sa_data[i];
    return (mac);
}