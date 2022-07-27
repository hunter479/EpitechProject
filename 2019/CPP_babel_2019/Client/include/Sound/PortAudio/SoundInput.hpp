/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** SoundInput
*/

#ifndef SOUNDINPUT_HPP_
#define SOUNDINPUT_HPP_

#include <mutex>
#include "IDataFlow.hpp"
#include "PortAudioM.hpp"
#include "CallManager.hpp"

class SoundInput : public IDataFlow {
	public:
		SoundInput();
		~SoundInput();

		void initInput();

		void startStream();
		void stopStream();
		void openStream();

		std::queue<Sound::Decoded>	&getBuffers(void) { return (_buffers); };

		static int recordCallback(const void *, void *, unsigned long, const PaStreamCallbackTimeInfo *, PaStreamCallbackFlags, void *);

	private:
		std::queue<Sound::Decoded>	_buffers;
		PaStreamParameters			_inputParameters;
		PaStream					*_stream;
		PaError						_err;
};

#endif /* !SOUNDINPUT_HPP_ */
