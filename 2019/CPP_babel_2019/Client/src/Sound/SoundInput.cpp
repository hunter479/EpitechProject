/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** SoundInput
*/

#include "SoundInput.hpp"

SoundInput::SoundInput()
{
    initInput();
}

SoundInput::~SoundInput()
{
}

void SoundInput::initInput()
{
    _inputParameters.device = Pa_GetDefaultInputDevice();
    if (_inputParameters.device == paNoDevice)
        std::cerr << "Error: No default input device.\n" << std::endl;
    _inputParameters.channelCount = NB_CHANNELS;
    _inputParameters.sampleFormat = PA_SAMPLE_TYPE;
    _inputParameters.suggestedLatency = Pa_GetDeviceInfo(_inputParameters.device)->defaultLowInputLatency;
    _inputParameters.hostApiSpecificStreamInfo = NULL;
}

int SoundInput::recordCallback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *data)
{
	SoundInput *currentInput = static_cast<SoundInput *>(data);
    CallManager *currentInstance = CallManager::getInstance();
    Sound::Decoded sound;

    sound.size = frameCount * NB_CHANNELS;
    sound.buffer.assign(static_cast<const float *>(input), static_cast<const float *>(input) + frameCount * NB_CHANNELS);

    currentInput->_buffers.push(sound);
    currentInstance->soundIsAvailable();

    return paContinue;
}

void SoundInput::openStream()
{
    _err = Pa_OpenStream(
                &_stream,
                &_inputParameters,
                NULL,
                SAMPLE_RATE,
                FRAMES_PER_BUFFER,
                paClipOff,
                SoundInput::recordCallback,
                this);
    if (_err != paNoError)
        std::cerr << Pa_GetErrorText(_err) << std::endl;
}

void SoundInput::startStream()
{
    _err = Pa_StartStream(_stream);
    if (_err != paNoError)
        std::cerr << Pa_GetErrorText(_err) << std::endl;
}

void SoundInput::stopStream()
{
    if (_stream)
        _err = Pa_StopStream(_stream);
    if (_err != paNoError)
        std::cerr << Pa_GetErrorText(_err) << std::endl;
}
