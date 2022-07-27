/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** Errors
*/

#include <string>
#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component)
{
    _message.assign(message);
    _component.assign(component);
}
