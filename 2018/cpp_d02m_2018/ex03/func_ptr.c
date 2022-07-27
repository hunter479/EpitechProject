/*
** EPITECH PROJECT, 2019
** func ptr
** File description:
** ex03
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "func_ptr.h"

void    print_normal(const char *str)
{
    printf("%s\n", str);
}

void    print_reverse(const char *str)
{
    int size = strlen(str) - 1;

    while (size >= 0) {
        write(1, &str[size], 1);
        size--;
    }
    write(1, "\n", 1);
}

void    print_upper(const char *str)
{
    int a = 0;

    while (str[a] != '\0') {
        if (str[a] >= 'a' && str[a] <= 'z')
            printf("%c", (str[a] - 32));
        else
            printf("%c", str[a]);
        a++;
    }
    printf("\n");
}

void    print_42(const char *str)
{
    printf("42\n");
}

void    do_action(action_t action, const char *str)
{
    void    (*func[4])(const char *);

    func[0] = &print_normal;
    func[1] = &print_reverse;
    func[2] = &print_upper;
    func[3] = &print_42;
    func[action](str);
}