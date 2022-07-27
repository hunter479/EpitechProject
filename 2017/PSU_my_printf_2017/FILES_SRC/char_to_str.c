/*
** EPITECH PROJECT, 2017
** char_to_char
** File description:
** transfer a char into a string
*/

#include <stdlib.h>

char	*char_to_str(char a)
{
	char	*str = " ";

	str = malloc(sizeof(char));
	str[0] = a;
	return (str);
}
