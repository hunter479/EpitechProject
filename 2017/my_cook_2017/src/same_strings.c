/*
** EPITECH PROJECT, 2018
** same_strings
** File description:
** Return 1 if two strings are the same
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

int	same_strings(char *str1, char *str2)
{
	int	i = 0;

	if (str1 == NULL || str2 == NULL)
		return (0);
	while (str1[i] == str2[i]) {
		if (str1[i] == '\0' && str2[i] != '\0')
			return (0);
		if (str2[i] == '\0' && str1[i] != '\0')
			return (0);
		if (str1[i] == '\0' && str2[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
