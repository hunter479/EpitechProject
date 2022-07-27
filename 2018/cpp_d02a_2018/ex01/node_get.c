/*
** EPITECH PROJECT, 2019
** 2019
** File description:
** node_get
*/

#include <stdlib.h>
#include "simple_btree.h"

unsigned int    btree_get_depth(tree_t tree)
{
    unsigned int nb_l = 0;
    unsigned int nb_r = 0;

    if (!tree)
        return (0);
    if (!tree->left && !tree->right)
        return (1);
    if (tree->left != NULL)
        nb_l = btree_get_depth(tree->left);
    if (tree->right != NULL)
        nb_l = btree_get_depth(tree->right);
    if (nb_l > nb_r)
        return (nb_l + 1);
    else
        return (nb_r + 1);
}

double  btree_get_max_value(tree_t tree)
{
    double value_r = 0;
    double value_l = 0;
    double max = tree->value;

    if (!tree->left && !tree->right)
        return (tree->value);
    value_r = btree_get_max_value(tree->right);
    value_l = btree_get_max_value(tree->left);
    if (value_r >= max)
        max = value_r;
    if (value_l >= max)
        max = value_l;
    return (max);
}

double  btree_get_min_value(tree_t tree)
{
    double value_r = 0;
    double value_l = 0;
    double min = tree->value;

    if (!tree->left && !tree->right)
        return (tree->value);
    value_r = btree_get_min_value(tree->right);
    value_l = btree_get_min_value(tree->left);
    if (value_r <= min)
        min = value_r;
    if (value_l <= min)
        min = value_l;
    return (min);
}
