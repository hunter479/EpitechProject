/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** ex00
*/

#ifndef EX00_H_
# define EX00_H_

typedef struct s_cthulhu
{
    int m_power;
    char    *m_name;
} cthulhu_t;

typedef struct s_koala
{
    char m_is_a_legend;
    cthulhu_t m_parent;
} koala_t;

koala_t *new_koala(char *, char);
static void koala_initializer(koala_t *, char *, char);
cthulhu_t *new_cthulhu(void);
static void cthulhu_initializer(cthulhu_t *);
void print_power(cthulhu_t *);
void attack(cthulhu_t *);
void sleeping(cthulhu_t *);
void eat(koala_t *);

#endif /* !EX00_H_ */
