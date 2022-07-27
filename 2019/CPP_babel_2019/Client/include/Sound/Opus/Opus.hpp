/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** EncodeManager
*/

#ifndef OPUS_HPP_
#define OPUS_HPP_

#include "ICodec.hpp"
#include "Sound.hpp"
#include "opus.h"

class Opus : public ICodec {
	public:
		Opus();
		~Opus();

		Sound::Encoded	encode(const Sound::Decoded &sound);
		Sound::Decoded	decode(const Sound::Encoded &sound);

	private:
		OpusEncoder	*_encoder;
		OpusDecoder	*_decoder;
};

#endif /* !OPUS_HPP_ */
