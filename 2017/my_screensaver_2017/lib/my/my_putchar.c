/*
** EPITECH PROJECT, 2017
** push
** File description:
** s
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
	write (1, &c , 1);
}
