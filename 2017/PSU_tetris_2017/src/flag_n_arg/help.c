/*
** EPITECH PROJECT, 2018
** checking options
** File description:
** same
*/

#include <stdlib.h>
#include <unistd.h>
#include "nick.h"
#include "my.h"

int	display_help2(void)
{
	my_printf(" -d --key-drop={K}\tDROP the tetrimino");
	my_printf(" using the K key (def: down arrow)\n");
	my_printf(" -q --key-quit={K}\tQUIT the game using");
	my_printf(" the K key (def: 'q' key)\n");
	my_printf(" -p --key-pause={K}\tPAUSE/RESTART the game");
	my_printf(" using the K key (def: space bar)\n");
	my_printf(" --map-size={row,col}\tSet the numbers of rows");
	my_printf(" and columns of the map (def: 20,10)\n");
	my_printf(" -w --without-next\tHide next tetrimino (def: false)\n");
	my_printf(" -D --debug\t\tDebug mode (def: false)\n");
	return (0);
}

int	display_help(char *b_name)
{
	if (! b_name) {
		write(2, "Error: problem of binary\n", 25);
		return (-1);
	}
	my_printf("Usage: %s [options]\n", b_name);
	my_printf("Options:\n ");
	my_printf("--help\t\t\tDisplay this help\n ");
	my_printf("-L --level={num}\tStart Tetris at level num (def: 1)\n ");
	my_printf("-l --key-left={K}\tMove the tetrimino ");
	my_printf("LEFT using the K key (def: left arrow)\n ");
	my_printf("-r --key-right={K}\tMove the tetrimino");
	my_printf("RIGHT using the K key (def: right arrow)\n ");
	my_printf("-t --key-turn={K}\tTURN the tetrimino");
	my_printf("clockwise 90d using the K key (def: top arrow)\n ");
	display_help2();
	return (0);
}
