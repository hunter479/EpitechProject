/*
** EPITECH PROJECT, 2017
** list.h
** File description:
** CPool_Day11_2017_Task11/2
*/

#ifndef LIST_H_
	#define LIST_H_

typedef struct			s_linked_list
{
	int			data;
	struct s_linked_list	*next;
	struct s_linked_list	*prev;
}				linked_list_t;

int	is_sorted(linked_list_t *);
int	my_params_to_list(int, char **, linked_list_t **);
void	my_free_list(linked_list_t **);
void	my_rev_list(linked_list_t **);
void	pa(linked_list_t **, linked_list_t **);
void	pb(linked_list_t **, linked_list_t **);
void	push_swap(linked_list_t **);
void	rra(linked_list_t **);
void	rrb(linked_list_t **);
void	sort(linked_list_t **, linked_list_t **);
void	sort2(linked_list_t **, linked_list_t **, linked_list_t **);

#endif /* !LIST_H_ */