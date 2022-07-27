/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** info
*/

#ifndef INFO_HPP_
    #define INFO_HPP_

namespace arcade {
    namespace state {
        typedef enum state_e {
            Username,
            Menu,
            Game,
            End,
        } state_t;
    }
    namespace key {
        typedef enum key_e {
            noaction,
            f2,
            f3,
            f4,
            f5,
            enter,
            escape,
            backspace,
            z,
            q,
            s,
            d,
        } key_t;
    }
}

#endif /* !INFO_HPP_ */
