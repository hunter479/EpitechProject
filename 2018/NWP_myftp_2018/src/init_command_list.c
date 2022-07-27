/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** init_command_list
*/

#include "server.h"

command_t *init_command_list_2(command_t *list)
{
    list[6].name = "HELP";
    list[6].command = &help_command;
    list[7].name = "CWD";
    list[7].command = &cwd_command;
    list[8].name = "PASV";
    list[8].command = &pasv_command;
    list[9].name = "LIST";
    list[9].command = &list_command;
    list[10].name = "RETR";
    list[10].command = &retr_command;
    list[11].name = "DELE";
    list[11].command = &dele_command;
    list[12].name = "STOR";
    list[12].command = &stor_command;
    list[13].name = "PORT";
    list[13].command = &port_command;
    list[14].name = NULL;
    return (list);
}

command_t *init_command_list(void)
{
    command_t *list = malloc(sizeof(command_t) * 16);

    if (!list)
        return (NULL);
    list[0].name = "USER";
    list[0].command = &user_command;
    list[1].name = "PASS";
    list[1].command = &pass_command;
    list[2].name = "QUIT";
    list[2].command = &quit_command;
    list[3].name = "PWD";
    list[3].command = &pwd_command;
    list[4].name = "CDUP";
    list[4].command = &cdup_command;
    list[5].name = "NOOP";
    list[5].command = &noop_command;
    list = init_command_list_2(list);
    return (list);
}