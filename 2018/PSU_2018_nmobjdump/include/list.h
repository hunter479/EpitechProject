/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** list
*/

#ifndef LIST_H_
# define LIST_H_

#include <elf.h>
#include <stdio.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_list {
    int addr;
    char type;
    char *name;
    struct s_list *next;
}   list_t;

typedef struct s_elf32 {
    Elf32_Shdr *shdr;
    Elf32_Ehdr *ehdr;
    Elf32_Sym *sym;
} elf32_t;

typedef struct s_elf64 {
    Elf64_Shdr *shdr;
    Elf64_Ehdr *ehdr;
    Elf64_Sym *sym;
} elf64_t;

/*  x64  */
int     check_format64(Elf64_Ehdr *);
char	check_type_lowcase64(Elf64_Sym, char);
char	check_shtype64(uint16_t, Elf64_Shdr *);
char	check_shndx64(Elf64_Sym);
char	check_wv64(Elf64_Sym);
char    *get_strtab64(Elf64_Ehdr *, Elf64_Shdr *, void *, int *);
Elf64_Sym *get_symtab64(Elf64_Ehdr *, Elf64_Shdr *, void *, int *);
int get_shsize64(Elf64_Ehdr *, Elf64_Shdr *);
char get_type64(Elf64_Sym sym, Elf64_Shdr *);
list_t  *get_info64(elf64_t, void *);
elf64_t   prep_struct64(void *);
int	check_size64(char *file, void *data, Elf64_Ehdr *ehdr);
int my_nm64(char *, int, void *);


/*  x86  */
int     check_format32(Elf32_Ehdr *);
char	check_type_lowcase32(Elf32_Sym, char);
char	check_shtype32(uint16_t, Elf32_Shdr *);
char	check_shndx32(Elf32_Sym);
char	check_wv32(Elf32_Sym);
char    *get_strtab32(Elf32_Ehdr *, Elf32_Shdr *, void *, int *);
Elf32_Sym *get_symtab32(Elf32_Ehdr *, Elf32_Shdr *, void *, int *);
int get_shsize32(Elf32_Ehdr *, Elf32_Shdr *);
char get_type32(Elf32_Sym sym, Elf32_Shdr *shdr);
list_t  *get_info32(elf32_t, void *);
elf32_t   prep_struct32(void *);
int	check_size32(char *file, void *data, Elf32_Ehdr *elf);
int my_nm32(char *, int, void *);

/*  neutra  */
void    clean_list(list_t **);
list_t  *create_list(int, char, char *);
void    put_in_list(list_t **, list_t *);
void    print_info(list_t *);

/*  OBJ  */
/*  x64  */
int my_obj64(char *file, void *);
int     check_sec_print64(char *, Elf64_Ehdr *, Elf64_Shdr);
void    print_name64(unsigned char *, Elf64_Shdr, int);
void    print_hexa_addr64(unsigned char *, Elf64_Shdr, int);
void    print_section64(Elf64_Shdr, Elf64_Ehdr *, char *, void *);
void    print_content64(elf64_t, void *);
void    print_start_address64(Elf64_Ehdr *);
int	    get_objsymtab64(elf64_t);
int get_flags64(elf64_t);
void    print_flag64(int, char *);

/*  x86  */
int my_obj32(char *file, void *);
int     check_sec_print32(char *, Elf32_Ehdr *, Elf32_Shdr);
void    print_name32(unsigned char *, Elf32_Shdr, int i);
void    print_hexa_addr32(unsigned char *, Elf32_Shdr, int i);
void    print_section32(Elf32_Shdr, Elf32_Ehdr *, char *, void *);
void    print_content32(elf32_t, void *);
void    print_start_address32(Elf32_Ehdr *);
int	    get_objsymtab32(elf32_t);
int get_flags32(elf32_t);
void    print_flag32(int, char *);

/*  neutral  */
int	    flags_list(int);

/*  BOTH  */
void    *get_map(int, struct stat, char *);
void    *get_buf(char *, struct stat *, char *);
void	sort(list_t **);
int check_access(char *, char *);

#endif /* !LIST_H_ */