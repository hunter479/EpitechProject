/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** history
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <curses.h>
#include <string.h>
#include "my.h"

char	*only_com(char *his)
{
	int	mal = 0;
	char	*tmp = NULL;

	for (mal = 0; his[mal] != '\t'; mal++);
	mal += 1;
	for (; his[mal] != '\t'; mal++);
	mal += 1;
	tmp = my_strdup(his + mal);
	return (tmp);
}

void	history_action(mysh_t *ms, cursor_t *cursor, int *i)
{
	for (int b = my_strlen(cursor->buf); b != 0; b --) {
		action("dc");
		action("le");
	}
	cursor->buf = only_com(ms->his[size_tab(ms->his) - 1 - cursor->y]);
	write(1, cursor->buf, strlen(cursor->buf));
	*i = my_strlen(cursor->buf);
	return;
}

void	history_action2(mysh_t *ms, cursor_t *cursor, int *i)
{
	for (int b = my_strlen(cursor->buf); b != 0; b --) {
		action("dc");
		action("le");
	}
	cursor->buf = only_com(ms->his[size_tab(ms->his) + 1 - cursor->y]);
	write(1, cursor->buf, strlen(cursor->buf));
	*i = my_strlen(cursor->buf);
	return;
}

int	history_key(mysh_t *ms, int k, cursor_t *cursor, int *i)
{
	if (k == 1) {
		if (ms->his != NULL && cursor->y < size_tab(ms->his)) {
			history_action(ms, cursor, i);
			cursor->y += 1;
		}
		else
			return (1);
	}
	if (k == 2) {
		if (ms->his != NULL && cursor->y > 1) {
			history_action2(ms, cursor, i);
			cursor->y -= 1;
		}
		else
			return (1);
	}
	return (1);
}