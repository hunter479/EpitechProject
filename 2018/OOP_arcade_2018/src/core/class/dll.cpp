/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** dll
*/

#include <dlfcn.h>
#include <iostream>
#include "dll.hpp"

template <class T>
dll<T>::~dll()
{
    delete so;
    dlclose(this->handler);
}

template <class T>
dll<T>::dll(const char *path, const char *func)
{
    this->handler = dlopen(path, RTLD_NOW);
    T *(*pointer)();

    if (!this->handler)
        throw std::invalid_argument(dlerror());
    pointer = reinterpret_cast<T *(*)()>(dlsym(this->handler, func));
    if (!pointer) {
        so = NULL;
        throw std::invalid_argument(dlerror());
    }
    this->so = pointer();
}