/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** IPortAudio
*/

#ifndef IDATAFLOW_HPP_
#define IDATAFLOW_HPP_

#include <queue>
#include <iostream>
#include <list>
#include "portaudio.h"
#include "Sound.hpp"

class IDataFlow {
	public:
		virtual ~IDataFlow() {};

		virtual void startStream() = 0;
		virtual void stopStream() = 0;
		virtual void openStream() = 0;

		virtual std::queue<Sound::Decoded> &getBuffers(void) = 0;
};

#endif /* !IDATAFLOW_HPP_ */
