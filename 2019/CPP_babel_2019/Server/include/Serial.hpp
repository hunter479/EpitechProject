/*
** EPITECH PROJECT, 2019
** Server
** File description:
** Serial
*/

#ifndef SERIAL_HPP_
#define SERIAL_HPP_

#include <string>
#include <iostream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>

class Serial {
	public:
		template<typename T>
		static const std::string save(const T *);
		template<typename T>
		static T *load(const std::string &);
	private:
		Serial() {};
		~Serial() {};
		Serial(const Serial &) = delete;
		Serial &operator=(const Serial &) = delete;
};

template<typename T>
const std::string Serial::save(const T *to_serialize)
{
    try {
        std::ostringstream oString;

        boost::archive::text_oarchive oss(oString);
        oss << to_serialize;
        return (std::string(oString.str()));
    } catch (std::exception &e) {
        std::cerr << "Serial::save: " << e.what() << std::endl;
        throw std::exception();
    }
}

template<typename T>
T *Serial::load(const std::string &serialized)
{
    try {
        T *ret = nullptr;

        if (serialized.empty() == true)
            return (nullptr);
        std::istringstream iss(serialized);
        boost::archive::text_iarchive ia(iss);
        ia >> ret;
        return (ret);
    } catch (std::exception &e) {
        std::cerr << "Serial::load: " << e.what() << std::endl;
        throw (std::exception());
    }
}

#endif /* !SERIAL_HPP_ */
