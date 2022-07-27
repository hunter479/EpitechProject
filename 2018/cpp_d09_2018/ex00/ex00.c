/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** ex00
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ex00.h"

void eat(koala_t *this)
{
    if (!this)
        return;
    printf("%s eats\n", this->m_parent.m_name);
    this->m_parent.m_power += 42;
}

void sleeping(cthulhu_t *this)
{
    if (!this || !this->m_name)
        return;
    printf("%s sleeps\n", this->m_name);
    this->m_power += 42000;
}

void attack(cthulhu_t *this)
{
    if (!this || !this->m_name)
        return;
    if (this->m_power < 42) {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
        return;
    } else {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    }
}

void print_power(cthulhu_t *this)
{
    if (!this)
        return;
    printf("Power => %d\n", this->m_power);
}


static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = "Cthulhu";
    this->m_power = 42;
    printf("Building Cthulhu\n");
}


cthulhu_t *new_cthulhu(void)
{
    cthulhu_t *new = malloc(sizeof(cthulhu_t));

    if (!new)
        return (NULL);
    printf("----\n");
    cthulhu_initializer(new);
    return (new);
}

static void koala_initializer(koala_t *this, char *_name, char  _is_A_Legend)
{
    this->m_parent = *new_cthulhu();
    if (_is_A_Legend == 0)
        this->m_parent.m_power = 0;
    printf("Building %s\n", _name);
    this->m_is_a_legend = _is_A_Legend;
    this->m_parent.m_name = _name;
}

koala_t *new_koala(char *name , char is_a_legend)
{
    koala_t *new = malloc(sizeof(koala_t));

    if (!name || !new)
        return (NULL);
    koala_initializer(new, name, is_a_legend);
    return (new);
}
