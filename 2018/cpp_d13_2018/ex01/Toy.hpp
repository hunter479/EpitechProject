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
            ALIEN
        } ToyType;
        Toy(const Toy &);
		Toy(ToyType type = BASIC_TOY, const std::string &name = "toy", const std::string &filename = "");
		~Toy();
        const Toy &operator=(const Toy &);
        const std::string getName() const {return (_name);};
        void setName(const std::string &name) {_name.assign(name);};
        ToyType getType() const {return (_type);};
        bool setAscii(const std::string &filename);
        const std::string getAscii() const {return (_picture.data);};
	protected:
	private:
        Picture _picture;
        ToyType _type;
        std::string _name;
};

#endif /* !TOY_HPP_ */
