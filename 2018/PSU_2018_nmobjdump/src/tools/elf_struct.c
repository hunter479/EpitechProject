/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** elf_struct
*/

#include <stdlib.h>
#include "list.h"

elf32_t   prep_struct32(void *buf)
{
    elf32_t   elf;

    elf.ehdr = (Elf32_Ehdr *)buf;
    elf.shdr = (Elf32_Shdr *)(buf + elf.ehdr->e_shoff);
    elf.sym = NULL;
    if (check_format32(elf.ehdr) == 1) {
        fprintf(stderr, "my_nm : format files unknow\n");
        elf.ehdr = NULL;
        return (elf);
    }
    return (elf);
}

elf64_t   prep_struct64(void *buf)
{
    elf64_t   elf;

    elf.ehdr = (Elf64_Ehdr *)buf;
    elf.shdr = (Elf64_Shdr *)(buf + elf.ehdr->e_shoff);
    elf.sym = NULL;
    if (check_format64(elf.ehdr) == 1) {
        fprintf(stderr, "my_nm : format files unknow\n");
        elf.ehdr = NULL;
        return (elf);
    }
    return (elf);
}
