/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** check
*/

#include "list.h"

char    check_wv32(Elf32_Sym sym)
{
    if (ELF32_ST_BIND(sym.st_info) == STB_WEAK) {
        if (ELF32_ST_TYPE(sym.st_info) == STT_OBJECT)
            return ('V');
        return ('W');
    }
    return (0);
}

char    check_shndx32(Elf32_Sym sym)
{
    if (sym.st_shndx == SHN_UNDEF)
        return ('U');
    if (sym.st_shndx == SHN_ABS)
        return ('A');
    if (sym.st_shndx == SHN_COMMON)
        return ('C');
    return (0);
}

char    check_shtype32(uint16_t i, Elf32_Shdr *shdr)
{
    if (shdr[i].sh_type == SHT_NOBITS
        && shdr[i].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return ('B');
    if (shdr[i].sh_type == SHT_PROGBITS
        && (shdr[i].sh_flags == SHF_ALLOC
        || shdr[i].sh_flags == (SHF_MERGE | SHF_ALLOC)))
        return ('R');
    if ((shdr[i].sh_type == SHT_PROGBITS
        && shdr[i].sh_flags == (SHF_ALLOC | SHF_WRITE))
        || shdr[i].sh_type == SHT_DYNAMIC)
        return ('D');
    if ((shdr[i].sh_type == SHT_PROGBITS
        && shdr[i].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        || shdr[i].sh_type == SHT_INIT_ARRAY
        || shdr[i].sh_type == SHT_FINI_ARRAY)
        return ('T');
    return (0);
}

char	check_type_lowcase32(Elf32_Sym sym, char type)
{
    if ((ELF32_ST_BIND(sym.st_info) == STB_LOCAL && type != 0)
        || ((type == 'W' || type == 'V') && sym.st_shndx == SHN_UNDEF))
        type += 32;
    return (type);
}
