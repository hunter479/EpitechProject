/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** arrow
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <curses.h>
#include <string.h>
#include "my.h"

int	left_or_right(int c, int *i, cursor_t *cursor)
{
	char	*left = tigetstr("kcub1");
	char	*right = tigetstr("kcuf1");

	if ((c == left[strlen(left) - 1]) && (*i > 0)) {
		action("le");
		*i -= 1;
		if (*i < 0)
			*i = 0;
		cursor->x = (*i);
		return (2);
	}
	if ((c == right[strlen(right) - 1]) && (*i < my_strlen(cursor->buf))) {
		action("nd");
		*i += 1;
		cursor->x = (*i);
		return (2);
	}
	return (0);
}

int	is_arrow(mysh_t *ms, char c, cursor_t *cursor, int *i)
{
	char	*up = tigetstr("kcuu1");
	char	*down = tigetstr("kcud1");

	if (c == 127 || !up || !down || c == 9)
		return (0);
	c = getchar();
	c = getchar();
	if (c == up[strlen(up) - 1])
		return (history_key(ms, 1, cursor, i));
	if (c == down[strlen(down) - 1])
		return (history_key(ms, 2, cursor, i));
	return (left_or_right(c, i, cursor));
}