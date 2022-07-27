/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** IEncode
*/

#ifndef ICODEC_HPP_
#define ICODEC_HPP_

#include "Sound.hpp"

class ICodec {
	public:
		virtual ~ICodec() {};
		virtual Sound::Encoded	encode(const Sound::Decoded &) = 0;
		virtual Sound::Decoded	decode(const Sound::Encoded &) = 0;
};

#endif /* !ICODEC_HPP_ */
