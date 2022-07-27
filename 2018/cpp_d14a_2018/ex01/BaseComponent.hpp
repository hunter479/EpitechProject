/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** BaseComponent
*/

#ifndef BASE_COMPONENT_HPP_
    #define BASE_COMPONENT_HPP_

#include "Errors.hpp"

// Base class for all rover's components.
class BaseComponent
{
    public:
        BaseComponent() : a(NasaError("")) {};
        virtual ~BaseComponent() {};
    protected:
        NasaError a;
};

#endif /* !BASE_COMPONENT_HPP_ */
