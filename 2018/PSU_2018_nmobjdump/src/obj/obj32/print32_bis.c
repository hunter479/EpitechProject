/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** print32_bis
*/

#include "list.h"

void    print_start_address32(Elf32_Ehdr *elf)
{
    printf("start address 0x%016x\n\n", (int)elf->e_entry);
}
