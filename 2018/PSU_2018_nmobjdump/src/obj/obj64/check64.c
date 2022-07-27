/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** check64
*/

#include <stdio.h>
#include <string.h>
#include "flags.h"
#include "list.h"

int     check_sec_print64(char *str, Elf64_Ehdr *ehdr, Elf64_Shdr shdr)
{
    char *tab[6] = {".bss", ".symtab", ".strtab", ".str", ".shstrtab", "\0"};
    int i = 0;

    if (ehdr->e_type == ET_REL) {
        if (shdr.sh_type == SHT_RELA || shdr.sh_type == SHT_NOTE)
            return (1);
    }
    while (i < 6) {
        if (strcmp(str, tab[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}