/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** string
*/

#ifndef STRING_H_
# define STRING_H_

typedef struct  s_str
{
    char    *str;
    void        (*assign_s)(struct s_str *, const struct s_str *);
    void        (*assign_c)(struct s_str *, const char *);
    void        (*append_s)(struct s_str *, const struct s_str *);
    void        (*append_c)(struct s_str *, const char *);
    void        (*string_destroy)(struct s_str *);
    char        (*at)(const struct s_str *, size_t);
    void        (*clear)(struct s_str *);
    int         (*size)(const struct s_str *);
    int         (*compare_s)(const struct s_str *, const struct s_str *);
    int         (*compare_c)(const struct s_str *, const char *);
    size_t      (*copy)(const struct s_str *, char *, size_t, size_t);
    const char  *(*c_str)(const struct s_str *);
    int         (*empty)(const struct s_str *);
    int         (*find_s)(const struct s_str *, const struct s_str *, size_t);
    int         (*find_c)(const struct s_str *, const char *, size_t);
    void        (*insert_c)(struct s_str *, size_t, const char *);
    void        (*insert_s)(struct s_str *, size_t, const struct s_str *);
    int         (*to_int)(const struct s_str *);
}   string_t;

    void        assign_s(struct s_str *, const struct s_str *);
    void        assign_c(struct s_str *, const char *);
    void        append_s(struct s_str *, const struct s_str *);
    void        append_c(struct s_str *, const char *);
    char        at(const struct s_str *, size_t);
    void        clear(struct s_str *);
    int         size(const struct s_str *);
    int         compare_s(const struct s_str *, const struct s_str *);
    int         compare_c(const struct s_str *, const char *);
    size_t      copy(const struct s_str *, char *, size_t, size_t);
    const char  *c_str(const struct s_str *);
    int         empty(const struct s_str *);
    int         find_s(const struct s_str *, const struct s_str *, size_t);
    int         find_c(const struct s_str *, const char *, size_t);
    void        insert_c(struct s_str *, size_t, const char *);
    void        insert_s(struct s_str *, size_t, const struct s_str *);
    int         to_int(const struct s_str *);
    void        string_init(struct s_str *, const char *);
    void        string_destroy(struct s_str *);

#endif /* !STRING_H_ */
