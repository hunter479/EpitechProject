/*
** EPITECH PROJECT, 2019
** NWP_my_arsp_2018
** File description:
** handle_option
*/

#include <netdb.h>
#include <ctype.h>
#include "myserver.h"

int check_ip(const char *str)
{
    int i = 0;

    if (!str)
        return (-1);
    while (str[i] != '\0') {
        if (isdigit(str[i]) || str[i] == '.')
            i++;
        else
            return (-1);
    }
    return (1);
}

int check_mac(uint8_t *str, my_arsp_t *serv)
{
    if (str == NULL)
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i]) || str[i] == ':')
            i++;
        else
            return (-1);
    }
    serv->dest_mac = get_mac(str);
    return (1);
}

int recup_rest_arg(my_arsp_t *serv, char **av)
{
    if (serv->printSpoof != NULL && serv->printBroadcast == 1)
        return (-1);
    if (av[optind + 3] != NULL)
        return (-1);
    if (check_mac(serv->printSpoof, serv) == -1)
        return (-1);
    if (check_ip(av[optind]) == -1 || check_ip(av[optind + 1]) == -1)
        return (-1);
    serv->source_ip = strdup(av[optind]);
    serv->dest_ip = strdup(av[optind + 1]);
    serv->interface = strdup(av[optind + 2]);
    return (0);
}

uint8_t *copy_mac(const char *str)
{
    int len = strlen(str);
    char *mac = malloc(sizeof(char) * (len + 2));

    memset(mac, 0, len + 2);
    mac = strcpy(mac, str);
    return ((uint8_t *)mac);
}

int parse_option(my_arsp_t *serv, int ac, char **av)
{
    int opt = 0;
    int idx = 0;
    static struct option long_options[4] = {
        {"printBroadcast", no_argument, 0, '0'},
        {"printSpoof", required_argument, 0, '1'},
        {0, 0, 0, 0}
    };
    init_var(serv);
    while ((opt = getopt_long(ac, av, "01:", long_options, &idx)) != -1) {
        switch (opt) {
            case '0':
                serv->printBroadcast = 1;
                break;
            case '1':
                serv->printSpoof = copy_mac(optarg);
                break;
            case '?':
                return (-1);
        }
    }
    return (recup_rest_arg(serv, av));
}
