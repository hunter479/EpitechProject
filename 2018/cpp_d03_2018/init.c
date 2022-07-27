/*
** EPITECH PROJECT, 2019
** cpp_d03_2018
** File description:
** append_and_assign
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string.h"

void    string_init(string_t *this, const char *s)
{
    if (s)
        this->str = strdup(s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
}
