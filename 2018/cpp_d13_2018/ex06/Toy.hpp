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
        Toy(const Toy &ref) {*this = ref;};
		Toy(ToyType, const std::string &, const std::string &);
		virtual ~Toy();
        class Error {
            public:
            typedef enum {
                UNKNOWN,
                PICTURE,
                SPEAK
            } ErrorType;
                Error() {};
                ~Error() {};
                void setType(const ErrorType ref) {type = ref;};
                ErrorType getType(void) const {return (type);};
                const std::string what() const;
                const std::string where() const;
                ErrorType type;
        };
        Toy &operator=(const Toy &);
        Toy &operator<<(std::string str);
        const std::string getName() const {return (_name);};
        void setName(const std::string &name) {_name.assign(name);};
        ToyType getType() {return (_type);};
        bool setAscii(const std::string &filename);
        const std::string getAscii() const {return (_picture.data);};
        virtual bool speak(const std::string &);
        virtual bool speak_es(const std::string &) {err.setType(Error::SPEAK); return (false);};
        virtual const Error getLastError();
	protected:
        Error err;
        Picture _picture;
        ToyType _type;
        std::string _name;
	private:
};
std::ostream &operator<<(std::ostream &os, const Toy &other);

#endif /* !TOY_HPP_ */
