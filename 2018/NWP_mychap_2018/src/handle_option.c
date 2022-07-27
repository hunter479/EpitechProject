/*
** EPITECH PROJECT, 2019
** NWP_mychap_2018
** File description:
** handle_option
*/

#include <netdb.h>
#include <ctype.h>
#include "myserver.h"

static int get_port(const char *str)
{
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else {
            return_usage(84);
            exit(84);
        }
    }
    return (atoi(str));
}

char *get_ip(const char *str)
{
    struct hostent *host = gethostbyname(str);
    struct in_addr **addr_list = host ?
    (struct in_addr **)host->h_addr_list : NULL;

    if (host == NULL) {
        printf("No such hostname: '%s'\n", str);
        exit(84);
    }
    return (strdup(inet_ntoa(*addr_list[0])));
}

static void recup_cmd(mychap_t *serv, int opt)
{
    switch (opt) {
        case '?':
            return_usage(84);
            exit(84);
            break;
        case 't':
            serv->target = get_ip(optarg);
            break;
        case 'P':
            serv->password = strdup(optarg);
            break;
        case 'p':
            serv->port = get_port(optarg);
            break;
    }
}

int parse_option(mychap_t *serv, int ac, char **av)
{
    int opt = 0;
    int idx = 0;
    static struct option long_options[4] = {
        {"target", required_argument, 0, 't'},
        {"port", required_argument, 0, 'p'},
        {"password", required_argument, 0, 'P'},
        {0, 0, 0, 0}
    };

    init_var(serv);
    while ((opt = getopt_long(ac, av, "t:p:P:", long_options, &idx)) != -1)
        recup_cmd(serv, opt);
    if (av[optind] != NULL || serv->target == NULL || serv->password == NULL ||
    serv->port == -1)
        return (1);
    return (0);
}
