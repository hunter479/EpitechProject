/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** dll
*/

#ifndef DLL_HPP_
    #define DLL_HPP_

#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

template <class T>
class dll
{
    public:
        dll(const char *, const char *);
        ~dll();

        T *so;
    private:
        void *handler;
};

template class dll<IDisplayModule>;
template class dll<IGame>;

#endif /* !DLL_HPP_ */
