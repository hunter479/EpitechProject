/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** check64_flags
*/


#include "list.h"

char	check_wv64(Elf64_Sym sym)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK) {
        if (ELF64_ST_TYPE(sym.st_info) == STT_OBJECT)
            return ('V');
        return ('W');
    }
    return (0);
}

char	check_shndx64(Elf64_Sym sym)
{
    if (sym.st_shndx == SHN_UNDEF)
        return ('U');
    if (sym.st_shndx == SHN_ABS)
        return ('A');
    if (sym.st_shndx == SHN_COMMON)
        return ('C');
    return (0);
}

char	check_shtype64(uint16_t i, Elf64_Shdr *shdr)
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

char	check_type_lowcase64(Elf64_Sym sym, char type)
{
    if ((ELF64_ST_BIND(sym.st_info) == STB_LOCAL && type != 0)
        || ((type == 'W' || type == 'V') && sym.st_shndx == SHN_UNDEF))
        type += 32;
    return (type);
}
