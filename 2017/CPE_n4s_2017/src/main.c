/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "struct.h"
#include "n4s.h"

void	my_parse(char *str, val_t *val)
{
	val->top = 0;
	val->left = 0;
	val->right = 0;
	for (int i = 0; i < 3; str ++) {
		if (str == NULL || str[0] == '\0')
			exit(1);
		if (str[0] == ':')
			i += 1;
	}
	str += get_left_value(val, str);
	str += get_top_value(val, str);
	get_right_value(val, str);
	val->lsize = cos(60 * (M_PI / 180)) * val->left;
	val->rsize = cos(60 * (M_PI / 180)) * val->right;
	val->mid = (val->lsize + val->rsize);
	left_or_right(val);
	get_clear(str);
	return;
}

void	get_info(char *line, val_t *val)
{
	size_t	size = 0;

	while (1) {
		my_putstr("GET_INFO_LIDAR\n");
		getline(&line, &size, stdin);
		write(2, "\n", 1);
		my_parse(line, val);
	}
	return;
}

int	main(void)
{
	char	*line = NULL;
	val_t	val;

	start_and_move(line);
	get_info(line, &val);
	return (0);
}
