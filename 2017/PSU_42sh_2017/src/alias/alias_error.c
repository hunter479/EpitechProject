/*
** EPITECH PROJECT, 2018
** error for alias file
** File description:
** checl
*/

#include "my.h"

int	alias_error(int err)
{
	if (err != 0) {
		my_putstr("example : alias ll=ls -l\n");
	}
	return (0);
}
