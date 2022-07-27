/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** EncodeManager
*/

#include <iostream>
#include "Opus.hpp"

Opus::Opus(void) {
	int error;

	_encoder = opus_encoder_create(24000, NB_CHANNELS, OPUS_APPLICATION_VOIP, &error);
	if (error != OPUS_OK)
        std::cerr << "failed" << std::endl;

	_decoder = opus_decoder_create(24000, NB_CHANNELS, &error);
	if (error != OPUS_OK)
        std::cerr << "failed" << std::endl;
}

Opus::~Opus(void) {
	if (_encoder)
		opus_encoder_destroy(_encoder);

	if (_decoder)
		opus_decoder_destroy(_decoder);
}

Sound::Encoded	Opus::encode(const Sound::Decoded &sound) {
	Sound::Encoded encoded;

	encoded.buffer.resize(sound.size);
	encoded.size = opus_encode_float(_encoder, sound.buffer.data(), FRAMES_PER_BUFFER, encoded.buffer.data(), sound.size);

	if (encoded.size < 0)
		std::cerr << "Failed 1" << std::endl;

	return encoded;
}

Sound::Decoded	Opus::decode(const Sound::Encoded &sound) {
	Sound::Decoded decoded;

	decoded.buffer.resize(FRAMES_PER_BUFFER * NB_CHANNELS);
	decoded.size = opus_decode_float(_decoder, sound.buffer.data(), sound.size, decoded.buffer.data(), FRAMES_PER_BUFFER, 0) * NB_CHANNELS;

	if (decoded.size < 0)
		std::cerr << "Failed 2" << std::endl;

	return decoded;
}