/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** getting stats
*/

#include "my_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>

char	*get_date(struct stat file, int to_disp)
{
	char	*date = malloc(sizeof(char *) * 15);
	int	i = 4;
	int	a = -1;
	char	*tmp = ctime(&file.st_mtime);

	while (++a != 15)
		date[a] = '0';
	a = 0;
	while (i <= 15) {
		date[a] = tmp[i];
		a++;
		i++;
	}
	date[a] = '\0';
	if (to_disp == 1)
		my_printf("%s ", date);
	return (date);
}

int	get_size(struct stat file)
{
	int	size = file.st_size;
	my_printf("%d ", size);
	return (size);
}

char	*get_id(struct stat file)
{
	struct	passwd *userid = getpwuid(file.st_uid);
	struct	group *grpid = getgrgid(file.st_gid);
	char	*user = userid->pw_name;
	char	*grp = grpid->gr_name;

	my_printf("%s %s ", user, grp);
}

int	get_link(struct stat file)
{
	int	link = 0;

	link = file.st_nlink;
	my_printf("%d ", link);
	return (link);
}

char	*get_rights(struct stat file, char *path)
{
	char	*rights = malloc(sizeof(char) * 11);
	int	a = -1;

	while (++a != 11)
		rights[a] = '0';
	rights[0] = entity_type(path);
	rights[1] = (file.st_mode & S_IRUSR) ? 'r' : '-';
	rights[2] = (file.st_mode & S_IWUSR) ? 'w' : '-';
	rights[3] = (file.st_mode & S_IXUSR) ? 'x' : '-';
	rights[4] = (file.st_mode & S_IRGRP) ? 'r' : '-';
	rights[5] = (file.st_mode & S_IWGRP) ? 'w' : '-';
	rights[6] = (file.st_mode & S_IXGRP) ? 'x' : '-';
	rights[7] = (file.st_mode & S_IROTH) ? 'r' : '-';
	rights[8] = (file.st_mode & S_IWOTH) ? 'w' : '-';
	rights[9] = (file.st_mode & S_IXOTH) ? 'x' : '-';
	rights[10] = '\0';
	my_printf("%s ", rights);
	return (rights);
}