/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** Parts
*/

#ifndef PARTS_HPP_
	#define PARTS_HPP_

#include <string>

class Arms {
    public:
        Arms(const std::string &serial = "A-01", bool functionnal = true);
        ~Arms();
        bool isFunctionnal(void) const;
        std::string serial(void) const;
        void informations(void) const;
    private:
        std::string _serial;
        bool _functionnal;
};

class Legs {
    public:
        Legs(const std::string &serial = "L-01", bool functionnal = true);
        ~Legs();
        bool isFunctionnal(void) const;
        std::string serial(void) const;
        void informations(void) const;
    private:
        std::string _serial;
        bool _functionnal;
};

class Head {
    public:
        Head(const std::string &serial = "H-01", bool functionnal = true);
        ~Head();
        bool isFunctionnal(void) const;
        std::string serial(void) const;
        void informations(void) const;
    private:
        std::string _serial;
        bool _functionnal;
};

#endif /* !PARTS_HPP_ */
