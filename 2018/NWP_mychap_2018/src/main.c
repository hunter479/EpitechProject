/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** main
*/

#include "myserver.h"

int mychap(mychap_t *serv)
{
    if (package_procedure(serv, "client hello") == 1)
        return (84);
    if (strcmp((const char *)(serv->answer), "Protocol Mismatch") == 0) {
        printf("Protocol Mismatch\n");
        return (0);
    }
    serv->hash = do_sha((const char *)serv->answer, serv->password);
    if (package_procedure(serv, (const char *)serv->hash) == 1)
        return (84);
    if (strcmp((const char *)(serv->answer), "KO") == 0)
        printf("KO\n");
    else
        printf("Secret: '%s'\n", serv->answer);
    return (0);
}

int main(int ac, char **av)
{
    mychap_t serv;

    if (ac != 7)
        return (return_usage(84));
    if (parse_option(&serv, ac, av) == 1)
        return (return_usage(84));
    init_struct(&serv);
    return (mychap(&serv));
}