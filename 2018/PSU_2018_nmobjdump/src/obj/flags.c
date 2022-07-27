/*
** EPITECH PROJECT, 2019
** PSU_2018_nmobjdump
** File description:
** flags
*/

#include <stdio.h>
#include "flags.h"

int	flags_list(int flags)
{
    char    *name_flags[10] = {"BFD_NO_FLAGS", "HAS_RELOC", "EXEC_P",
        "HAS_LINENO", "HAS_DEBUG", "HAS_SYMS", "HAS_LOCALS", "DYNAMIC",
        "WP_TEXT", "D_PAGED"};
    int tab_flags[10] = {BFD_NO_FLAGS, HAS_RELOC, EXEC_P, HAS_LINENO,
        HAS_DEBUG, HAS_SYMS, HAS_LOCALS, DYNAMIC, WP_TEXT, D_PAGED};
    int	i = 0;
    int	tmp = 0;

    while (i <= 10) {
        tmp = flags;
        if ((flags & tab_flags[i]) != 0) {
            flags -= tab_flags[i];
            printf("%s", name_flags[i]);
        }
        if ((i != 0 && flags != 0) && flags != tmp)
            printf(", ");
        i += 1;
    }
    return (flags);
}
