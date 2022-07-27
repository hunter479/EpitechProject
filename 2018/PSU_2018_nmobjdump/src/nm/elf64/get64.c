/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** get64
*/

#include "list.h"

int get_shsize64(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr)
{
    int i = 0;

    while (i < ehdr->e_shnum) {
        if (shdr[i].sh_type == SHT_SYMTAB)
            return (shdr[i].sh_size / shdr[i].sh_entsize);
        i++;
    }
    return (0);
}

char get_type64(Elf64_Sym sym, Elf64_Shdr *shdr)
{
    char type = 0;

    type = (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE) ? 'u' : 0;
    if (type == 0) {
        if (check_wv64(sym) != 0)
            type = check_wv64(sym);
        else if (check_shndx64(sym) != 0)
            type = check_shndx64(sym);
        else
            type = check_shtype64(sym.st_shndx, shdr);
    }
    type = check_type_lowcase64(sym, type);
    return (type);
}

list_t  *get_info64(elf64_t elf, void *buf)
{
    int i = 0;
    int size = get_shsize64(elf.ehdr, elf.shdr);
    char    *str = NULL;
    char type = 0;
    list_t  *list = NULL;

    elf.sym = get_symtab64(elf.ehdr, elf.shdr, buf, &i);
    str = get_strtab64(elf.ehdr, elf.shdr, buf, &i);
    if (elf.sym == NULL || str == NULL)
        return (NULL);
    i = 0;
    while (i < size) {
        type = get_type64(elf.sym[i], elf.shdr);
        if (type != 0 && elf.sym[i].st_shndx != SHN_ABS
            && (str + elf.sym[i].st_name)[0] != '\0')
            put_in_list(&list, create_list(elf.sym[i].st_value,
            type, str + elf.sym[i].st_name));
        i++;
    }
    return (list);
}

char *get_strtab64(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, void *buf, int *i)
{
    char *name = NULL;

    while (*i < ehdr->e_shnum) {
        if (shdr[*i].sh_type == SHT_STRTAB) {
            name = (char *)(buf + shdr[*i].sh_offset);
            return (name);
        }
        (*i)++;
    }
    return (NULL);
}

Elf64_Sym *get_symtab64(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, void *buf, int *i)
{
    Elf64_Sym *tab = NULL;

    while (*i < ehdr->e_shnum) {
        if (shdr[*i].sh_type == SHT_SYMTAB) {
            tab = (Elf64_Sym *)(buf + shdr[*i].sh_offset);
            return (tab);
        }
        (*i)++;
    }
    return (NULL);
}
