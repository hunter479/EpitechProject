/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** get
*/

#include "list.h"

void  *get_map(int fd, struct stat s, char *bin)
{
    void    *buf = NULL;

    if (fd != -1) {
        buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        if (buf == NULL)
            fprintf(stderr, "%s: mmap failed\n", bin);
        close(fd);
    }
    return (buf);
}

int check_access(char *file, char *bin)
{
    if (access(file, F_OK) != 0) {
        fprintf(stderr, "%s: '%s': No such file\n", bin, file);
        return (1);
    }
    if (access(file, R_OK) != 0) {
        fprintf(stderr, "%s: %s: Permission denied\n", bin, file);
        return (1);
    }
    return (0);
}

void *get_buf(char *file, struct stat *st, char *bin)
{
    int fd = open(file, O_RDONLY);
    struct  stat s;
    void    *buf = NULL;

    if (check_access(file, bin) == 1)
        return (NULL);
    fstat(fd, &s);
    if (s.st_size == 0)
        return (NULL);
    if (S_ISDIR(s.st_mode) == 1) {
        fprintf(stderr, "%s: Warning: '%s' is a directory\n", bin, file);
        return (NULL);
    }
    buf = get_map(fd, s, bin);
    *st = s;
    return (buf);
}
