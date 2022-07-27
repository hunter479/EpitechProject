/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** get64
*/

#include "flags.h"
#include "list.h"

int	get_objsymtab64(elf64_t elf)
{
    int	i = 0;

    while (i < elf.ehdr->e_shnum) {
        if (elf.shdr[i].sh_type == SHT_SYMTAB)
            return (HAS_SYMS);
        i += 1;
    }
    return (BFD_NO_FLAGS);
}

int get_flags64(elf64_t elf)
{
    int	flags = BFD_NO_FLAGS;

    if (elf.ehdr->e_type == ET_EXEC)
        flags += EXEC_P + D_PAGED;
    if (elf.ehdr->e_type == ET_DYN)
        flags += DYNAMIC + D_PAGED;
    if (elf.ehdr->e_type == ET_REL)
        flags += HAS_RELOC;
    flags += get_objsymtab64(elf);
    return (flags);
}
