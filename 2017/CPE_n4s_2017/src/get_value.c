/*
** EPITECH PROJECT, 2018
** get value
** File description:
** get value
*/

#include <stdio.h>
#include <stdlib.h>
#include "n4s.h"

void	get_solo_value(int pos, int count, int *val, char *str)
{
	if (count == pos)
		*val = atoi(str);
	return;
}

int	get_left_value(val_t *val, char *str)
{
	int	ret = 0;
	int	count = 0;

	for (int x = 0, bool = 1; str[x] && count <= 10; str ++, ret += 1) {
		if (str[x] == ':') {
			count += 1;
			bool = 1;
		}
		else if (bool == 1) {
			get_solo_value(0, count, &val->sleft, str);
			val->left += atoi(str);
			bool = 0;
		}
	}
	val->left = val->left / 11;
	return (ret);
}

int	get_top_value(val_t *val, char *str)
{
	int	ret = 0;
	int	count = 0;

	for (int x = 0, bool = 1; str[x] && count <= 10; str ++, ret += 1) {
		if (str[x] == ':') {
			count += 1;
			bool = 1;
		}
		else if (bool == 1) {
			get_solo_value(5, count, &val->stop, str);
			val->top += atoi(str);
			bool = 0;
		}
	}
	val->top = val->top / 11;
	return (ret);
}

void	get_right_value(val_t *val, char *str)
{
	int	count = 0;

	for (int x = 0, bool = 1; str[x] && count <= 9; str ++) {
		if (str[x] == ':') {
			count += 1;
			bool = 1;
		}
		else if (bool == 1) {
			get_solo_value(9, count, &val->sright, str);
			val->right += atoi(str);
			bool = 0;
		}
	}
	val->right = val->right / 10;
	return;
}