/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** .h for my_ls
*/

#ifndef MY_LS_H_
	#define MY_LS_H_

#define FLAGS	"lRdrt"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[1;34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[1;36m"
#define RESET   "\x1b[0m"
#define ENOTDIR_str "my_ls: cannot access '%s' : "

#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

typedef	struct	s_flags
{
	char	l;
	char	mr;
	char	d;
	char	r;
	char	t;
}		t_flags;

typedef	struct	s_stack
{
	char	*data;
	struct	s_stack *next;
}		stack_t;

int	my_printf(char *, ...);
int	get_modif(struct stat file);
int	my_strlen(char const *);
void	put_in_list(char *, stack_t **);
void	sort(stack_t **, char);
int	type_detect(char, void *, char *);
void	scan_repo(char *str, int a, t_flags flags);
char	entity_type(char *);
void	*my_memset(void *, int, int);
void	listing(stack_t *, t_flags);
int	size_list(stack_t *);
char	*catpath(char *, char *);
int	my_strcmp(char const *, char const *);
void	my_rev_list(stack_t **begin);
stack_t	*to_merge(stack_t *list, stack_t *list2);
stack_t	*sorted_merge_file(stack_t *a, stack_t *b);
stack_t	*sorted_merge_dir(stack_t *a, stack_t *b);
stack_t	*sorted_merge_modif(stack_t *a, stack_t *b);
char	*get_date(struct stat file, int);
long	total_block(stack_t *list, char *path);
int	get_link(struct stat file);
char	*get_rights(struct stat file, char *);
int	get_size(struct stat file);
char	*get_id(struct stat file);
char	*get_stats(char *path, int);
int	my_putstr(char const *str);
void	sort_by_time(stack_t **id, char *path);
char	*dest_add_src(char *dest, char *src);
char	*cut_str(char *str, int a);
char	 *my_strlowcase(char *str);
char	*int_to_charstr(int);
int	my_getnbr(char const *str);
void	flag_d(stack_t **stack, t_flags flags);
void	flag(t_flags flags, stack_t *files, char *str);
void	errno_d(DIR *repo, char *str, t_flags flags);

#endif /* !MY_LS_H_ */
