/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** Cesar
*/

#ifndef CESAR_HPP_
	#define CESAR_HPP_

#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod{
	public:
		Cesar();
		~Cesar();
		void encryptChar(char plainchar);
		void decryptChar(char cipherchar);
		void reset();
	protected:
        int intervalle;
	private:
};

#endif /* !CESAR_HPP_ */
