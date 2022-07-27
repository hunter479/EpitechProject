/*
** EPITECH PROJECT, 2019
** cpp_d13_2018
** File description:
** Toy
*/

#ifndef TOY_HPP_
	#define TOY_HPP_

#include <string>
#include "Picture.hpp"

class Toy {
	public:
        typedef enum {
            BASIC_TOY,
            BUZZ,
            WOODY,
            ALIEN
        } ToyType;
		Toy(ToyType, const std::string &, const std::string &);
        Toy(const Toy &ref) {*this = ref;};
		virtual ~Toy();
        const Toy &operator=(const Toy &);
        Toy &operator<<(const std::string str);
        const std::string getName() const {return (_name);};
        ToyType getType() {return (_type);};
        bool setAscii(const std::string &filename);
        const std::string getAscii() const {return (_picture.data);};
        virtual bool speak(const std::string &);
        void setName(const std::string &name) {_name.assign(name);};
	protected:
        Picture _picture;
        ToyType _type;
        std::string _name;
};
std::ostream &operator<<(std::ostream &os, const Toy &other);

#endif /* !TOY_HPP_ */
