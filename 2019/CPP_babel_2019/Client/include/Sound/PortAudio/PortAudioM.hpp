/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** PortAudioM
*/

#ifndef PORTAUDIOM_HPP_
#define PORTAUDIOM_HPP_

#include "ISoundDevice.hpp"
#include "ICodec.hpp"

class PortAudioM : public ISoundDevice {
	public:
		PortAudioM();
		~PortAudioM();

        IDataFlow *getInput() { return (_soundInputM); };
        IDataFlow *getOutput() { return (_soundOutputM); };

	private:
		IDataFlow	*_soundInputM;
		IDataFlow	*_soundOutputM;
};

#endif /* !PORTAUDIOM_HPP_ */
