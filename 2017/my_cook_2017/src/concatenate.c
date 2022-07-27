/*
** EPITECH PROJECT, 2018
** concatenate
** File description:
** Concatenate two strings and return the result
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

int	my_strlen(char const *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

char	*concat_strings(char *str1, char *str2)
{
	int	i = 0;
	char	*to_re = malloc(my_strlen(str1) + my_strlen(str2) + 2);

	while (i != my_strlen(str1)) {
		to_re[i] = str1[i];
		i++;
	}
	while (i != my_strlen(str1) + my_strlen(str2)) {
		to_re[i] = str2[i - my_strlen(str1)];
		i++;
	}
	to_re[i] = '\0';
	return (to_re);
}

int	count_len(char *str1, char *str2)
{
	int	len = 0;
	int	i = 0;

	while (str1[i] != '\0') {
		len++;
		i++;
	}
	i = 0;
	while (str2[i] != '\0') {
		len++;
		i++;
	}
	return (len);
}

char	*paste_word(int *i, char *str, char *to_return)
{
	int	j = 0;

	while (str[j] != '\0') {
		to_return[*i] = str[j];
		*i += 1;
		j++;
	}
	return (to_return);
}

char	*concatenate(char *str1, char *str2)
{
	int	i = 0;
	int	len;
	char	*to_return;

	if (str1 != NULL) {
		len = count_len(str1, str2) + 2;
		to_return = malloc(sizeof(char) * len);
		to_return = paste_word(&i, str1, to_return);
		to_return[i] = ';';
		i++;
	}
	else {
		len = count_len("", str2) + 1;
		to_return = malloc(sizeof(char) * len);
	}
	to_return = paste_word(&i, str2, to_return);
	to_return[len - 1] = '\0';
	return (to_return);
}
