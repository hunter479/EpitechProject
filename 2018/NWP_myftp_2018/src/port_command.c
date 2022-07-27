/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** port_command
*/

#include <ctype.h>
#include "server.h"

static int check_port(char **tmp, server_t *serv)
{

    int calc = 0;
    int ret = 0;

    calc = (atoi(tmp[4]) * 256) + atoi((tmp[5]));
    if (calc < 1000 || calc >= 65535) {
        send_rcode(serv->data.fd, "500 Illegal PORT command.\r\n");
        ret = -1;
    }
    for (int i = 0; tmp[i] ; free(tmp[i]), i++);
    return (ret);
}

static int check_addr(char *str, server_t *serv)
{
    char **tmp = NULL;
    int i = 0;
    int a = 0;

    while (str != NULL && str[i] != '\0') {
        if (str[i] == ',')
            a++;
        else if (isdigit(str[i]) == 0)
            break;
        i++;
    }
    if (a != 5) {
        send_rcode(serv->data.fd, "500 Illegal PORT command.\r\n");
        return (-1);
    }
    tmp = str_to_tab(str, ',');
    closefds(serv);
    return (check_port(tmp, serv));
}

void parse_addr(char *str, char **addr, int *port1, int *port2)
{
    char **tmp = str_to_tab(str, ',');
    char *addr_buff = malloc(sizeof(char) * strlen(str) + 1);

    if (!addr_buff) {
        fprintf(stderr, "malloc");
        return;
    }
    sprintf(addr_buff, "%s.%s.%s.%s", tmp[0], tmp[1], tmp[2], tmp[3]);
    *port1 = atoi(tmp[4]);
    *port2 = atoi(tmp[5]);
    *addr = addr_buff;
    for (int i = 0; tmp[i]; free(tmp[i]), i++);
    return;
}

void port_actv(sock_t data, server_t *serv)
{
    serv->transfer_data.fd = connect(data.fd, (struct sockaddr *)
    &data.addr, sizeof(struct sockaddr_in));
    if (serv->transfer_data.fd == -1) {
        perror("connect() error");
        send_rcode(serv->data.fd, "425 Cannot Connect To The Port.\r\n");
        return;
    }
    serv->transfer_sock = data;
    serv->mode = PORT;
    send_rcode(serv->data.fd, "200 Connected To The Port.\r\n");
}

void port_command(char **tab, server_t *serv)
{
    char *addr = NULL;
    int port1 = 0;
    int port2 = 0;
    sock_t data;

    if (is_co(serv, 1) == 1 || check_addr(tab[1], serv) == -1)
        return;
    parse_addr(tab[1], &addr, &port1, &port2);
    if (!addr)
        return;
    data = init_socket(port1 * 256 + port2);
    data.addr.sin_addr.s_addr = inet_addr(addr);
    port_actv(data, serv);
}