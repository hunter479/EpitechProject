/*
** EPITECH PROJECT, 2018
** malloc_func
** File description:
** personnal malloc to write on the ouput error if malloc failed
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	*my_malloc(void *to_malloc, int size)
{
	if (size < 1)
		return (NULL);
	to_malloc = malloc(sizeof(to_malloc) * (size + 1));
	if (to_malloc)
		to_malloc = my_memset(to_malloc, 0,
		sizeof(to_malloc) * (size + 1));
	if (!to_malloc) {
		write(2, "Error: Malloc failed.", 21);
		return (NULL);
	} else
		return (to_malloc);
}