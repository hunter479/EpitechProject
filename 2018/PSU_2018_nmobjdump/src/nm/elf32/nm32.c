/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** nm32
*/

#include "list.h"

int my_nm32(char *file, int ac, void *buf)
{
    elf32_t   elf;
    list_t  *list = NULL;

    elf = prep_struct32(buf);
    if (elf.ehdr == NULL || check_size32(file, buf, elf.ehdr) == 1)
        return (1);
    if (ac > 2)
        printf("\n%s:\n", file);
    list = get_info32(elf, buf);
    if (!list)
        fprintf(stderr, "my_nm: %s: no symbols\n", file);
    sort(&list);
    print_info(list);
    clean_list(&list);
    return (0);
}