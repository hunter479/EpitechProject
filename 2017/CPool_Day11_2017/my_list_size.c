/*
** EPITECH PROJECT, 2017
** my_list_size.c
** File description:
** CPool_Day11_2017_Task02
*/

#include <stdlib.h>
#include "mylist.h"
#include <unistd.h>

int *my_list_size(linked_list_t const *begin)
{
	linked_list_t	*list = begin;
	int j = 0;

	while (list != NULL) {
		list = list->next;
		j++;
	}

	return (j);
}