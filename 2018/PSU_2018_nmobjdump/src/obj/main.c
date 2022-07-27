/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** main
*/


#include <stdio.h>
#include <string.h>
#include "list.h"

int launch_obj(char *file)
{
    void    *buf = NULL;
    int ret = 0;
    struct  stat s;

    buf = get_buf(file, &s, "my_objdump");
    if (buf == NULL)
        return (1);
    if (((Elf64_Ehdr *)buf)->e_ident[EI_CLASS] == ELFCLASS64)
        ret = my_obj64(file, buf);
    else if (((Elf32_Ehdr *)buf)->e_ident[EI_CLASS] == ELFCLASS32)
        ret = my_obj32(file, buf);
    else {
        fprintf(stderr, "my_objdump: %s: File format not recognized\n", file);
        return (1);
    }
    if (munmap(buf, s.st_size) == -1)
        return (1);
    return (ret);
}

int my_objdump(int ac, char **av)
{
    int i = 1;
    int ret = 0;

    if (ac == 1)
        return (launch_obj("./a.out"));
    while (av[i] != NULL) {
        ret += launch_obj(av[i]);
        i++;
    }
    if (ret != 0)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    return (my_objdump(ac, av));
}
