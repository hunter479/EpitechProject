/*
** EPITECH PROJECT, 2018
** oui
** File description:
** oui
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include "nick.h"

int	change_key(keys_t *keys, char **av, int j, int k)
{
	if (!av[j + 1])
		return (84);
	else {
		switch (k) {
		case (5):
			keys->left = av[j + 1];
			return (1);
		case (7):
			keys->right = av[j + 1];
			return (1);
		case (9):
			keys->turn = av[j + 1];
			return (1);
		}
		return (change_key2(keys, av, j, k));
	}
}

int	change_key2(keys_t *keys, char **av, int j, int k)
{
	switch (k) {
	case (11):
		keys->drop = av[j + 1];
		return (1);
	case (13):
		keys->quit = av[j + 1];
		return (1);
	case (15):
		keys->pause = av[j + 1];
		return (1);
	}
	return (0);
}

int	key_change(keys_t *keys, char **av, int j, int k)
{
	char	*tmp = NULL;
	int	i = 0;

	while (av[j][i] != '=')
		i += 1;
	tmp = my_strdup(av[j] + i + 1);
	if (!tmp[0])
		return (84);
	switch (k) {
	case (6):
		keys->left = tmp;
		return (0);
	case (8):
		keys->right = tmp;
		return (0);
	}
	return (key_change2(keys, tmp, k));
}

int	key_change2(keys_t *keys, char *tmp, int k)
{
	switch (k) {
	case (10):
		keys->turn = tmp;
		return (0);
	case (12):
		keys->drop = tmp;
		return (0);
	case (14):
		keys->quit = tmp;
		return (0);
	case (16):
		keys->pause = tmp;
		return (0);
	}
	return (0);
}
