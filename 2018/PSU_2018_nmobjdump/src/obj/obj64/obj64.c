/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** obj64
*/

#include <stdio.h>
#include <string.h>
#include "flags.h"
#include "list.h"

int my_obj64(char *file, void *buf)
{
    elf64_t elf;
    int flags = BFD_NO_FLAGS;

    elf = prep_struct64(buf);
    if (elf.ehdr == NULL  || check_size64(file, buf, elf.ehdr) == 1)
        return (1);
    flags = get_flags64(elf);
    if (flags == BFD_NO_FLAGS)
        return (1);
    else
        print_flag64(flags, file);
    print_start_address64(elf.ehdr);
    print_content64(elf, buf);
    return (0);
}
