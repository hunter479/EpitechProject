/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** my_getstr
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <curses.h>
#include <string.h>
#include "my.h"

void	action(char *cmd)
{
	char	*a = NULL;

	a = tgetstr(cmd, NULL);
	write(1, a, strlen(a));
	return;
}

cursor_t	init_cursor(void)
{
	cursor_t	cursor;

	cursor.x = -1;
	cursor.y = 0;
	cursor.buf = malloc(sizeof(char) * 256);
	cursor.buf[0] = '\0';
	return (cursor);
}

int	getch_it_detect(int c, cursor_t *cursor, mysh_t *ms, int *i)
{
	if (c == 10)
		return (1);
	if (c == 4)
		return (2);
	if (c > 31 && c < 127)
		getch_write(cursor, i, c);
	else if (c == 127 && *i > 0)
		delete_char(cursor, i);
	else
		is_arrow(ms, c, cursor, i);
	return (0);
}

char	*getch_it(mysh_t *ms)
{
	int	c = 1;
	int	size = 1;
	int	i = 0;
	int	status	= 0;
	cursor_t	cur;

	cur = init_cursor();
	while (1) {
		c = getchar();
		if (my_strlen(cur.buf) > (250 * size)) {
			size++;
			cur.buf = realloc(cur.buf, sizeof(char) * (256 * size));
		}
		status = getch_it_detect(c, &cur, ms, &i);
		if (status == 1)
			break;
		else if (status == 2)
			return (NULL);
	}
	return (cur.buf);
}

char	*getch_line(mysh_t *ms, char **env)
{
	char	*tmp = NULL;

	if (init_term(env) == -1) {
		ms->ret = 1;
		return (NULL);
	}
	if (setupterm(NULL, 0, NULL) < 0) {
		ms->ret = 1;
		return (NULL);
	}
	tmp = getch_it(ms);
	my_printf("\n");
	if (reset_term(env) == -1) {
		ms->ret = 1;
		return (NULL);
	}
	return (tmp);
}