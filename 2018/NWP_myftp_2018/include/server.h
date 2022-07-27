/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include "rfc.h"

typedef enum {
    PASV,
    PORT,
    NEUTRAL,
} pasv_t;

typedef struct select_s
{
    fd_set read_fds;
    struct timeval timeout;
} select_t;

typedef struct sock_s
{
    int fd;
    struct sockaddr_in addr;
    socklen_t addrlen;
    select_t slc;
} sock_t;

typedef struct server_s
{
    sock_t control;
    sock_t data;
    sock_t transfer_sock;
    sock_t transfer_data;

    int user_log;
    int state;
    char *user;
    pasv_t mode;
} server_t;

typedef struct command_s {
    void (*command)(char **, server_t *);
    char *name;
} command_t;

char *get_command(server_t *serv);
int do_select(sock_t *serv, const int sec, const int usec);
void send_rcode(const int fd, const char *rfc);
int bind_socket(sock_t *sock);
int server_launch(int port, char *path);
void free_tab(char **tab);
void parse_addr(char *str, char **addr, int *port1, int *port2);

// Init
sock_t init_socket(int port);
command_t *init_command_list();
command_t *init_command_list_2(command_t *list);
int init_var_struct(server_t *serv, char *path);
int init_server(server_t *server, int port, char *path);

// Command
void user_command(char **tab, server_t *serv);
void pass_command(char **tab, server_t *serv);
void port_command(char **tab, server_t *serv);
void dele_command(char **tab, server_t *serv);
void stor_command(char **tab, server_t *serv);
void quit_command(char **tab, server_t *serv);
void pasv_command(char **tab, server_t *serv);
void retr_command(char **tab, server_t *serv);
void cdup_command(char **tab, server_t *serv);
void noop_command(char **tab, server_t *serv);
void list_command(char **tab, server_t *serv);
void help_command(char **tab, server_t *serv);
void pwd_command(char **tab, server_t *serv);
void cwd_command(char **tab, server_t *serv);

// Client
int allow_connection(server_t *serv, command_t *);
int create_client(server_t *serv, command_t *);
void do_command(server_t *serv, command_t *);
int is_co(server_t *serv, const int opt);
int accept_sock(sock_t *data, int listen);

// Tools
int mode_check(server_t *serv);
char *get_current_dir_name(void);
char **str_to_tab(char *str, const char c);
char *get_sock_ip(sock_t serv, sock_t data);
int get_sock_port(sock_t data);
char *get_next_line(int fd);
int mode_check(server_t *serv);
void closefds(server_t *serv);

#endif /* !SERVER_H_ */
