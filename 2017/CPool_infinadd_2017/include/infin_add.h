/*
** EPITECH PROJECT, 2017
** infin_add
** File description:
** infin_add.h
*/

#ifndef INFIN_ADD_H_
# define INFIN_ADD_H_

char	*mmsigne(char *, char *, char *, int *);
int	error_managing(int, char *, char *);
char	*diffsigne(char *, char *, char *, int *);
char	*diffsigne2(char *, char *, char *, int *);
char	*calc_detect(char *, char *);
char	*sign_to_assign(char *, int, int, int);
char	*sign_check3(char *, int , int, int);
char	*sign_check2(char *, int, int, int);
char	*sign_check(char *, int, int);
char	*my_calc(char *, char *, char *, int);
void	no_neg(char **, char **, int *, int *);
char	*my_strset(char *, char *);
int	nbr_cmp(char *, char *, int, int);
int	bigger(char *, char*);
char	*somme_check(char *, char* , char *, int);
int	my_checksomme(char *, char *, char *);
int	w_no_minus(char *);

#endif /* !INFIN_ADD_H_ */
