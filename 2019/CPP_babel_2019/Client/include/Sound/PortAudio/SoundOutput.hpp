/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** SoundOutput
*/

#ifndef SOUNDOUTPUT_HPP_
#define SOUNDOUTPUT_HPP_

#include "Sound.hpp"
#include "IDataFlow.hpp"
#include "CallManager.hpp"

class SoundOutput : public IDataFlow {
	public:
		SoundOutput();
		~SoundOutput();

		void initOutput();

		void startStream();
		void stopStream();
		void openStream();

		std::queue<Sound::Decoded> &getBuffers(void) { return (_buffers); };

		static int playCallback(const void *, void *, unsigned long, const PaStreamCallbackTimeInfo *, PaStreamCallbackFlags, void *);

	private:
		std::queue<Sound::Decoded>	_buffers;
		PaStreamParameters			_outputParameters;
		PaStream					*_stream;
		PaError						_err;
};

#endif /* !SOUNDOUTPUT_HPP_ */
