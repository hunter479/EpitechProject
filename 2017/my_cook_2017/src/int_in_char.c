/*
** EPITECH PROJECT, 2018
** int_in_char
** File description:
** Receive an int and put it in a char *
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

char	*int_in_char(int nbr)
{
	char	*to_re;
	int	i = 0;
	int	nbrbis = nbr;

	while (nbrbis != 0) {
		i++;
		nbrbis = nbrbis / 10;
	}
	to_re = malloc(sizeof(i));
	to_re[i] = '\0';
	i--;
	while (nbr != 0) {
		to_re[i] = (nbr % 10) + '0';
		i--;
		nbr = nbr / 10;
	}
	return (to_re);
}
