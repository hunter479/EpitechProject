/*
** EPITECH PROJECT, 2019
** NWP_myftp_2018
** File description:
** gnl
*/

#include <unistd.h>
#include <stdlib.h>

int	strlen_gnl(const char *str)
{
    int	a = 0;

    while (str && str[a] != '\0')
        a++;
    return (a);
}

void gln_cpy(char *dest, char *src, int n)
{
    int	i;

    for (i = 0; src[i] && i < n; i++)
        dest[i] = src[i];
    if (src[i])
        dest[i] = '\0';
    return;
}

char *transfer_gnl(char *final, char *buf, int *begin, int done)
{
    char *to_mal = NULL;
    int	to_fgt = 0;

    final ? to_fgt = strlen_gnl(final) : (to_fgt = 0);
    to_mal = malloc(sizeof(char *) * (to_fgt + done + 1));
    final ? gln_cpy(to_mal, final, to_fgt) : gln_cpy(to_mal, "", to_fgt);
    to_mal[to_fgt + done] = 0;
    gln_cpy(to_mal + to_fgt, buf + *begin, done);
    if (final)
        free(final);
    *begin = *begin + (done + 1);
    return (to_mal);
}

char *get_next_line(int fd)
{
    static char	buf[1];
    static int	size = 0;
    char		*final = NULL;
    static int	begin = 0;

    for (int done = 0; 1; done += 1) {
        if (size <= begin) {
            begin = 0 + (0 * (done = 0));
            if (!(size = read(fd, buf, 1)))
                return (final);
            if (size == -1)
                return (NULL);
        }
        if (buf[begin + done] == '\n') {
            final = transfer_gnl(final, buf, &begin, done);
            return (final);
        }
        if (begin + done == size - 1)
            final = transfer_gnl(final, buf, &begin, done + 1);
    }
}
