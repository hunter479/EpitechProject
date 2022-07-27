/*
** EPITECH PROJECT, 2019
** simple tree
** File description:
** day02a
*/

#include <stdlib.h>
#include "simple_btree.h"

bool_t  btree_is_empty(tree_t tree)
{
    if (!tree)
        return (TRUE);
    else
        return (FALSE);
}

unsigned int    btree_get_size(tree_t tree)
{
    unsigned int nb_node = 0;

    if (!tree)
        return (0);
    if (tree->left)
        nb_node += btree_get_size(tree->left);
    if (tree->right)
        nb_node += btree_get_size(tree->right);
    nb_node++;
    return (nb_node);
}

bool_t  btree_create_node(tree_t *node_ptr, double value)
{
    tree_t new = malloc(sizeof(*new));

    if (!new)
        return (FALSE);
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    *node_ptr = new;
    return (TRUE);
}

bool_t  btree_delete(tree_t *root_ptr)
{
    if (!(*root_ptr))
        return (FALSE);
    *root_ptr = NULL;
    return (TRUE);
}
