/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** check
*/

#include "list.h"

int check_size32_bis(Elf32_Shdr *shdr, Elf32_Ehdr *ehdr, char *file, char *end)
{
    if ((char *)shdr > end) {
        fprintf(stderr, "my_objdump: %s: File truncated\n", file);
        return (1);
    }
    if ((char *)(shdr + (ehdr->e_shnum)) > end)  {
        fprintf(stderr, "my_objdump: %s: File truncated\n", file);
        return (1);
    }
    return (0);
}

int check_size32(char *file, void *data, Elf32_Ehdr *ehdr)
{
    Elf32_Shdr  *shdr;
    int fd = open(file, O_RDONLY);
    struct stat s;
    char        *end = NULL;

    shdr = (Elf32_Shdr *)(data + ehdr->e_shoff);
    fstat(fd, &s);
    end = data + s.st_size;
    if (ehdr->e_ehsize + (ehdr->e_phnum * ehdr->e_phentsize) +
    (ehdr->e_shnum * ehdr->e_shentsize) > s.st_size) {
        fprintf(stderr, "my_objdump: %s: File truncated\n", file);
        return (1);
    }
    return (check_size32_bis(shdr, ehdr, file, end));
}

int check_size64_bis(Elf64_Shdr *shdr, Elf64_Ehdr *ehdr, char *file, char *end)
{
    if ((char *)shdr > end) {
        fprintf(stderr, "my_objdump: %s: File truncated\n", file);
        return (1);
    }
    if ((char *)(shdr + (ehdr->e_shnum)) > end)  {
        fprintf(stderr, "my_objdump: %s: File truncated\n", file);
        return (1);
    }
    return (0);
}

int check_size64(char *file, void *data, Elf64_Ehdr *ehdr)
{
    Elf64_Shdr  *shdr;
    int fd = open(file, O_RDONLY);
    struct stat s;
    char        *end = NULL;

    shdr = (Elf64_Shdr *)(data + ehdr->e_shoff);
    fstat(fd, &s);
    end = data + s.st_size;
    if (ehdr->e_ehsize + (ehdr->e_phnum * ehdr->e_phentsize) +
    (ehdr->e_shnum * ehdr->e_shentsize) > s.st_size) {
        fprintf(stderr, "my_objdump: %s: File truncated\n", file);
        return (1);
    }
    return (check_size64_bis(shdr, ehdr, file, end));
}