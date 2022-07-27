/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** check
*/

#include "list.h"

int check_format64(Elf64_Ehdr *elf)
{
    if (elf->e_type == ET_REL)
        return (0);
    if (elf->e_type == ET_EXEC)
        return (0);
    if (elf->e_type == ET_DYN)
        return (0);
    return (1);
}

int check_format32(Elf32_Ehdr *elf)
{
    if (elf->e_type == ET_REL)
        return (0);
    if (elf->e_type == ET_EXEC)
        return (0);
    if (elf->e_type == ET_DYN)
        return (0);
    return (1);
}