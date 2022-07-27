/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include "list.h"

int launch_nm(char *file, int ac)
{
    void    *buf = NULL;
    int ret = 0;
    struct  stat s;

    buf = get_buf(file, &s, "my_nm");
    if (buf == NULL)
        return (1);
    if (((Elf64_Ehdr *)buf)->e_ident[EI_CLASS] == ELFCLASS64)
        ret = (my_nm64(file, ac, buf));
    else if (((Elf32_Ehdr *)buf)->e_ident[EI_CLASS] == ELFCLASS32)
        ret = (my_nm32(file, ac, buf));
    else {
        fprintf(stderr, "my_nm: %s: File format not recognized\n", file);
        return (1);
    }
    if (munmap(buf, s.st_size) == -1)
        return (1);
    return (ret);
}

int my_nm(int ac, char **av)
{
    int i = 1;
    int ret = 0;

    if (ac == 1)
        return (launch_nm("./a.out", 1));
    while (av[i] != NULL) {
        ret += launch_nm(av[i], ac);
        i++;
    }
    if (ret != 0)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    return (my_nm(ac, av));
}
