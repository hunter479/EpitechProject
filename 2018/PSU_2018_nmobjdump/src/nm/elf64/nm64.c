/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** nm64
*/

#include <stdlib.h>
#include "list.h"

int my_nm64(char *file, int ac, void *buf)
{
    elf64_t   elf;
    list_t  *list = NULL;

    elf = prep_struct64(buf);
    if (elf.ehdr == NULL || check_size64(file, buf, elf.ehdr) == 1)
        return (1);
    if (ac > 2)
        printf("\n%s:\n", file);
    list = get_info64(elf, buf);
    if (!list)
        fprintf(stderr, "my_nm: %s: no symbols\n", file);
    sort(&list);
    print_info(list);
    clean_list(&list);
    return (0);
}