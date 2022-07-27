/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
    #define IDISPLAYMODULE_HPP_

#include <string>
#include <vector>
#include "info.hpp"

class  IDisplayModule {
    public:
        virtual ~IDisplayModule() {};
        virtual void doEvent(std::string &) = 0;
        virtual void clean() = 0;
        virtual bool isOpen() const = 0;
        virtual void display() = 0;
        virtual void init(const arcade::state::state_t) = 0;
        virtual void draw(const std::vector<std::string> &) = 0;

        virtual arcade::key::key_t const &getKey() const = 0;
        virtual arcade::state::state_t const &getState() const = 0;
        virtual void setKey(const arcade::key::key_t) = 0;
        virtual void setState(const arcade::state::state_t &s) = 0;

        virtual void setName(std::string &) = 0;
    protected:
};

template <typename T>
T *loadLib(const char *);

#endif /* !IDISPLAYMODULE_HPP_ */
