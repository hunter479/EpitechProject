/*
** EPITECH PROJECT, 2018
** debug modde
** File description:
** ouo
*/

#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include "my.h"
#include "struct.h"
#include "proto.h"
#include "nick.h"

void	print_info(tetri_t *it)
{
	int	a = 0;

	if (!it)
		return;
	my_putstr("Tetriminos :");
	my_printf(" Name %s :", it->name);
	if (it->ok == -1) {
		my_putstr(" Error\n");
		return;
	}
	my_printf(" Size %d*%d :", it->x, it->y);
	my_printf(" Color %d :\n", it->color);
	if (it->form)
		while (it->form[a]) {
			my_putstr(it->form[a]);
			my_putstr("\n");
			a++;
		}
	return;
}

int	nb_tetri(tetri_t *it)
{
	tetri_t	*index = it;
	int	a = 0;

	while (index) {
		a++;
		index = index->next;
	}
	return (a);
}

void	tetri_print(tetri_t *it, keys_t *kt)
{
	int	a = nb_tetri(it);
	tetri_t	*tmp = it;

	my_printf("\nTetriminos : %d\n", a);
	while (tmp) {
		if (tmp->x > kt->row || tmp->y > kt->col)
			tmp->ok = -1;
		print_info(tmp);
		tmp = tmp->next;
	}
	return;
}

int	print_arrow(char *str)
{
	int	a = 0;

	while (str[a] != '\0') {
		if (str[a] == 27)
			write(1, "^E", 2);
		else
			write(1, &str[a], 1);
		a++;
	}
	return (0);
}

void	key_print(keys_t *keys)
{
	my_putstr("*** DEBUG MODE ***\nKey Left : ");
	(*keys->left != ' ') ? print_arrow(keys->left) : my_putstr("(space)");
	my_putstr("\nKey Right : ");
	(*keys->right != ' ') ? print_arrow(keys->right) : my_putstr("(space)");
	my_putstr("\nKey Turn : ");
	(*keys->turn != ' ') ? print_arrow(keys->turn) : my_putstr("(space)");
	my_putstr("\nKey Drop : ");
	(*keys->drop != ' ') ? print_arrow(keys->drop) : my_putstr("(space)");
	my_putstr("\nKey Quit : ");
	(*keys->quit != ' ') ? print_arrow(keys->quit) : my_putstr("(space)");
	my_putstr("\nKey Pause : ");
	(*keys->pause != ' ') ? print_arrow(keys->pause) : my_putstr("(space)");
	my_putstr("\nNext : ");
	(keys->next == 0) ? my_putstr("No") : my_putstr("Yes");
	my_printf("\nLevel : %d", keys->level);
	my_printf("\nSize : %d*%d", keys->row , keys->col);
	return;
}
