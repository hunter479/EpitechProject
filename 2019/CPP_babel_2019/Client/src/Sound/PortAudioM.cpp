/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** PortAudioM
*/

#include "PortAudioM.hpp"
#include "SoundInput.hpp"
#include "SoundOutput.hpp"

PortAudioM::PortAudioM()
{
    PaError err;

    err = Pa_Initialize();
    if (err != paNoError)
        std::cerr << Pa_GetErrorText(err) << std::endl;
    _soundInputM = new SoundInput;
    _soundOutputM = new SoundOutput;
}

PortAudioM::~PortAudioM()
{
    PaError err;

    err = Pa_Terminate();
    if (err != paNoError)
        std::cerr << Pa_GetErrorText(err) << std::endl;
    if (_soundInputM)
        delete _soundInputM;
    if (_soundOutputM)
        delete _soundOutputM;
}