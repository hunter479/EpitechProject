/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** write_it
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <curses.h>
#include <string.h>
#include "my.h"

void	delete_char(cursor_t *cursor, int *i)
{
	int	k = 0;
	char	*tmp = malloc(sizeof(char) * strlen(cursor->buf));

	action("le");
	action("dc");
	*i -= 1;
	cursor->x = *i;
	for (k = 0; k != cursor->x; k ++)
		tmp[k] = cursor->buf[k];
	if (cursor->buf[k] != '\0') {
		k += 1;
		for (int g = k - 1; cursor->buf[k] != '\0'; k ++, g ++)
			tmp[g] = cursor->buf[k];
		tmp[k - 1] = '\0';
	}
	else
		tmp[k] = '\0';
	cursor->buf = strcpy(cursor->buf, tmp);
	free(tmp);
	return;
}

void	write_key(cursor_t *cursor, int *i)
{
	for (int b = my_strlen(cursor->buf); b != 0; b --)
		action("dc");
	for (; *i > 0; (*i)--)
		action("le");
	return;
}

void	write_it(cursor_t *cursor, int *i, int c, char *tmp)
{
	if (tmp)
		free(tmp);
	cursor->buf[*i] = c;
	write(1, &cursor->buf[*i], 1);
	(*i)++;
	cursor->buf[*i] = '\0';
	return;
}

void	getch_write(cursor_t *cursor, int *i, int c)
{
	int	k = 0;
	char	*tmp = malloc(sizeof(char) * (strlen(cursor->buf) + 2));

	if (*i != my_strlen(cursor->buf)) {
		cursor->x = *i;
		write_key(cursor, i);
		for (k = 0; k != cursor->x; k ++)
			tmp[k] = cursor->buf[k];
		tmp[k] = c;
		for (int g = k + 1; cursor->buf[k] != '\0'; k++, g++)
			tmp[g] = cursor->buf[k];
		tmp[k + 1] = '\0';
		cursor->buf = strcpy(cursor->buf, tmp);
		write(1, cursor->buf, strlen(cursor->buf));
		*i = cursor->x + 1;
		for (int t = strlen(cursor->buf); t != cursor->x + 1; t--)
			action("le");
		free(tmp);
	}
	else
		write_it(cursor, i, c, tmp);
}
