/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** test list 2
*/

#include <criterion/criterion.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

Test(return_of_usage, check_status_usage)
{
	int	ac = 1;
	char	*av[2];
	char	**env = NULL;
	int	status = 0;

	av[1] = "-h";
	status = check(ac, av, env);
	cr_assert(status == 1);
}

Test(return_of_env_NULL, check_status_env)
{
	int	ac = 1;
	char	*av[2];
	char	*env[1];
	int	status = 0;

	av[1] = NULL;
	env[0] = NULL;
	status = check(ac, av, env);
	cr_assert(status == -1);
}

Test(return_of_get_name, check_value_of_display)
{
	char	*env[1];
	char	**tmp;

	env[0] = "DISPLAY=:1.1";
	tmp = get_name(env);
	cr_assert(my_strncmp("DISPLAY=:0.0", tmp[0], 7) == 0);
}
