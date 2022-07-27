/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** struct
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

typedef	struct		s_sh
{
	char	**env;
	char	*path;
	char	*home;
	char	*pwd;
}	sh_t;

#endif /* !MINISHELL_H_ */
