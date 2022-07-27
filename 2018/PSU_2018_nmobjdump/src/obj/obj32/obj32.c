/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** obj32
*/

#include <stdio.h>
#include <string.h>
#include "flags.h"
#include "list.h"

int my_obj32(char *file, void *buf)
{
    elf32_t elf;
    int flags = BFD_NO_FLAGS;

    elf = prep_struct32(buf);
    if (elf.ehdr == NULL || check_size32(file, buf, elf.ehdr) == 1)
        return (1);
    flags = get_flags32(elf);
    if (flags == BFD_NO_FLAGS)
        return (1);
    else
        print_flag32(flags, file);
    print_start_address32(elf.ehdr);
    print_content32(elf, buf);
    return (0);
}
