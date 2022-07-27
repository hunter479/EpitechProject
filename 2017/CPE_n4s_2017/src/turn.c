/*
** EPITECH PROJECT, 2018
** CPE_n4s_2017
** File description:
** turn
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "n4s.h"

int	move_straight(val_t *val)
{
	if (val->stop > 1200 && val->sleft > 150 &&
	val->sright > 150 && val->rsize > 200 && val->lsize > 200) {
		rotate_and_move(0, 0.85);
		return (1);
	}
	else
		return (0);
}

void	turn_right(val_t *val)
{
	if (val->lsize > 260) {
		rotate_and_move(-0.08, 0.45);
		return;
	}
	if (val->lsize > 225 && val->lsize < 260) {
		rotate_and_move(-0.2, 0.35);
		return;
	}
	if (val->rsize > val->lsize &&
	val->lsize > 170 && val->lsize < 225) {
		rotate_and_move(-0.29, 0.30);
		return;
	}
	if (val->rsize > val->lsize && val->lsize < 170) {
		rotate_and_move(-0.5, 0.2);
		return;
	}
	return;
}

void	turn_left(val_t *val)
{
	if (val->rsize > 260) {
		rotate_and_move(0.08, 0.45);
		return;
	}
	if (val->rsize > 225 && val->rsize < 260) {
		rotate_and_move(0.2, 0.35);
		return;
	}
	if (val->rsize > 170 && val->rsize < 225) {
		rotate_and_move(0.29, 0.30);
		return;
	}
	if (val->rsize < 170) {
		rotate_and_move(0.5, 0.2);
		return;
	}
	return;
}
