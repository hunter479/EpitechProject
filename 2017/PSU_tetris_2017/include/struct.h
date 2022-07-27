/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** structure
*/

#ifndef STRUCT_H_
#define STRUCT_H_


enum e_STATUS
{
	ERROR = -1
};

typedef struct s_tetris
{
	char	*name;
	int	ok;
	int	x;
	int	y;
	int	color;
	char	**form;
	struct s_tetris *next;
}	tetri_t;

#endif /* !STRUCT_H_ */
