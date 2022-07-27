/*
** EPITECH PROJECT, 2018
** move
** File description:
** move
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "n4s.h"

char	*rotate_and_move(double dir, double forward)
{
	char	*str = NULL;
	size_t	size = 0;

	printf("WHEELS_DIR:%f\n", dir);
	fflush(NULL);
	getline(&str, &size, stdin);
	is_ok(str);
	printf("CAR_FORWARD:%f\n", forward);
	fflush(NULL);
	getline(&str, &size, stdin);
	is_ok(str);
	return (str);
}

void	is_stuck(val_t *val)
{
	if (val->sleft == 0 || val->sright == 0) {
		send_cmd("WHEELS_DIR:0\n", 0);
		send_cmd("CAR_BACKWARDS:0.5\n", 0);
		send_cmd("CYCLE_WAIT:10\n", 0);
	}
	return;
}

void	left_or_right(val_t *val)
{
	if (move_straight(val) == 1)
		return;
	is_stuck(val);
	if (val->rsize > val->lsize)
		turn_right(val);
	if (val->lsize > val->rsize)
		turn_left(val);
	return;
}