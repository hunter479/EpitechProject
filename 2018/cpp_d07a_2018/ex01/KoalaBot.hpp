/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
        #define KOALABOT_HPP_

#include <string>
#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string serial = "Bob-01");
        ~KoalaBot();
        void setParts(const Arms &);
        void setParts(const Legs &);
        void setParts(const Head &);
        void swapParts(Arms &);
        void swapParts(Legs &);
        void swapParts(Head &);
        void informations() const;
        bool status() const;
    private:
        Arms _arms;
        Legs _legs;
        Head _head;
        std::string _serial;
};

#endif /* !KOALABOT_HPP_ */
