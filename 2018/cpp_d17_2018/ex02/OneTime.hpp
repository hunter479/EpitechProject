/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** OneTime
*/

#ifndef ONETIME_HPP_
	#define ONETIME_HPP_

#include <string>
#include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod{
	public:
		OneTime(const std::string &);
		~OneTime() {};
        void encryptChar(char);
		void decryptChar(char);
        void reset() {index = 0;};
	protected:
        int index;
        std::string key;
	private:
};

#endif /* !ONETIME_HPP_ */
