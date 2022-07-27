/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** cut parts of string
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

char	*cut_text(int *i, char *line)
{
	int	j = *i;
	int	k = 0;
	char	*to_return = 0;

	while (line[j] != ' ' && line[j] != '\t')
		j++;
	to_return = malloc(sizeof(char) * (j - *i) + 2);
	if (to_return == NULL)
		return (NULL);
	while (*i != j && line[*i] != '\n') {
		to_return[k] = line[*i];
		k++;
		*i += 1;
	}
	to_return[k] = '\0';
	*i += 1;
	return to_return;
}

float	cut_frac(int *i, char *line)
{
	int	j = *i;
	float	to_return = 0;

	while (line[j + 1] != ' ' && line[j] != '\t')
		j++;
	while (j != *i - 1) {
		to_return += (line[j] - '0');
		to_return /= 10;
		j--;
	}
	while (line[*i] != ' ' && line[*i] != '\t')
		*i += 1;
	return to_return;
}

float	cut_param(int *i, char *line)
{
	float	to_return = 0;
	int	sign = 1;

	if (line[*i] == '-') {
		*i += 1;
		sign = -1;
	}
	while (line[*i] != ' ' && line[*i] != '\t') {
		to_return *= 10;
		to_return += line[*i] - '0';
		*i += 1;
		if (line[*i] == '.') {
			*i += 1;
			to_return += cut_frac(i, line);
		}
	}
	*i += 1;
	to_return *= sign;
	return to_return;
}
