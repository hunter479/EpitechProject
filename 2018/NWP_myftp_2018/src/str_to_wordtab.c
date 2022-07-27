/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** word to tableau
*/

#include <stdlib.h>
#include <string.h>

int	nbr_word(char *str, const char c)
{
    int	a = 2;
    int	b = 0;

    while (str[b] != '\0') {
        if (str[b] == c)
            a++;
        b++;
    }
    return (a);
}

char **prep_new_string(char **final, int *i, int *a)
{
    final[*i][*a] = '\0';
    (*i)++;
    *a = 0;
    return (final);
}

char **tab_prep_tab(char **final, char *str, const char c)
{
    if (str == NULL)
        return (NULL);
    final = malloc(sizeof(char *) * (nbr_word(str, c) + 1));
    if (!final)
        return (NULL);
    final[0] = malloc(sizeof(char) * strlen(str) + 2);
    return (final);
}

char **str_to_tab(char *str, const char c)
{
    char **final = NULL;
    int	i = 0;
    int	a = 0;

    if ((final = tab_prep_tab(final, str, c)) == NULL)
        return (NULL);
    while (final[i] && str[0] != '\0') {
        if (str[0] == c || str[0] == '\r') {
            final = prep_new_string(final, &i, &a);
            final[i] = malloc(sizeof(char *) * strlen(str) + 1);
            str++;
        } else {
            final[i][a++] = str[0];
            str++;
        }
    }
    final[i++][a] = '\0';
    final[i] = NULL;
    return (final);
}
