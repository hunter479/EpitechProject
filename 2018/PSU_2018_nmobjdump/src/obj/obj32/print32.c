/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** print32
*/

#include <stdio.h>
#include <string.h>
#include "flags.h"
#include "list.h"

void    print_name32(unsigned char *str, Elf32_Shdr shdr, int i)
{
    int k = 0;

    while (k < 16) {
        if (k + i >= (int)shdr.sh_size)
            printf(" ");
        else if (str[k + i] < 32 || str[k + i] > 126)
            printf(".");
        else
            printf("%c", str[k + i]);
        k++;
    }
}

void    print_hexa_addr32(unsigned char *str, Elf32_Shdr shdr, int i)
{
    int k = 0;

    while (k < 16) {
        if (k + i >= (int)shdr.sh_size)
            printf("  ");
        else
            printf("%02x", str[k + i]);
        if ((k + 1) % 4 == 0)
            printf(" ");
        k++;
    }
}

void    print_section32(Elf32_Shdr shdr, Elf32_Ehdr *ehdr, char *str, void *buf)
{
    int i = 0;
    unsigned char *stock = buf + shdr.sh_offset;

    if (check_sec_print32(str + shdr.sh_name, ehdr, shdr) != 0
        || (int)shdr.sh_size == 0)
        return;
    printf("Contents of section %s:\n", str + shdr.sh_name);
    while (i < (int)shdr.sh_size) {
        if (shdr.sh_size / 16 >= 4097)
            printf(" %05x ", (int)shdr.sh_addr + i);
        else
            printf(" %04x ", (int)shdr.sh_addr + i);
        print_hexa_addr32(stock, shdr, i);
        printf(" ");
        print_name32(stock, shdr, i);
        printf("\n");
        i += 16;
    }
}

void    print_content32(elf32_t elf, void *buf)
{
    int i = 0;
    char *str = buf + elf.shdr[elf.ehdr->e_shstrndx].sh_offset;

    while (i < elf.ehdr->e_shnum) {
        print_section32(elf.shdr[i], elf.ehdr, str, buf);
        i += 1;
    }
}

void    print_flag32(int flags, char *file)
{
    printf("\n%s:     file format elf32-i386\n", file);
    printf("architecture: i386:x86-32, flags 0x%08x:\n", flags);
    flags = flags_list(flags);
    printf("\n");
}