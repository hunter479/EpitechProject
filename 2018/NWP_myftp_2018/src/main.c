/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** main
*/

#include <ctype.h>
#include <stdlib.h>
#include "server.h"

void print_usage(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("    port is the port number on which the server socket listens\n");
    printf("    path is the path to the home directory for the ");
    printf("Anonymous user\n");
}

int check_args(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help")) {
        print_usage();
        return (0);
    }
    if (ac != 3) {
        print_usage();
        return (1);
    }
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (isdigit(av[1][i]) == 0) {
            fprintf(stderr, "wrong model of port");
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    if (check_args(ac, av) != 0)
        return (84);
    return (server_launch(atoi(av[1]), av[2]));
}