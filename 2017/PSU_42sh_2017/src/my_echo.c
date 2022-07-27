/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** my_echo
*/

#include <unistd.h>
#include "my.h"

int	toggle_flags(char *arg, int *sf, int *nf, int *ef)
{
	if (arg[0] != '-')
		return (0);
	for (int i = 1; arg[i] != '\0'; i += 1) {
		*sf = (arg[i] == 's') ? 1 : *sf;
		*nf = (arg[i] == 'n') ? 1 : *nf;
		*ef = (arg[i] == 'E') ? 0 : *ef;
		*ef = (arg[i] == 'e') ? 1 : *ef;
	}
	return (0);
}

void	my_echo(mysh_t *ms)
{
	int	sf = 0;
	int	nf = 0;
	int	ef = 0;

	for (int i = 0; ms->arg[i]; i += 1)
		toggle_flags(ms->arg[i], &sf, &nf, &ef);
	for (int i = 1; ms->arg[i]; i += 1) {
		if (ms->arg[i][0] != '-')
			write(1, ms->arg[i], my_strlen(ms->arg[i]));
		if (sf != 1 && ms->arg[i + 1] != NULL && ms->arg[i][0] != '-')
			write(1, " ", 1);
	}
	if (nf != 1)
		write(1, "\n", 1);
	return;
}