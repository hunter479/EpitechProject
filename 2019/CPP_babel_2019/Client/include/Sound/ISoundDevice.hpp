/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** ISoundDevice
*/

#ifndef ISOUNDDEVICE_HPP_
#define ISOUNDDEVICE_HPP_

#include "IDataFlow.hpp"

class ISoundDevice {
	public:
		virtual ~ISoundDevice() {};
		virtual IDataFlow *getInput() = 0;
        virtual IDataFlow *getOutput() = 0;
};

#endif /* !ISOUNDDEVICE_HPP_ */
