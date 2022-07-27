/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** SoundOutput
*/

#include "SoundOutput.hpp"

SoundOutput::SoundOutput()
{
    initOutput();
}

SoundOutput::~SoundOutput()
{
    Pa_Terminate();
}

void SoundOutput::initOutput()
{
    _outputParameters.device = Pa_GetDefaultOutputDevice();
    if (_outputParameters.device == paNoDevice)
        std::cerr << "Error: No default output device.\n" << std::endl;
    _outputParameters.channelCount = NB_CHANNELS;
    _outputParameters.sampleFormat =  PA_SAMPLE_TYPE;
    _outputParameters.suggestedLatency = Pa_GetDeviceInfo( _outputParameters.device )->defaultLowOutputLatency;
    _outputParameters.hostApiSpecificStreamInfo = NULL;
}

int SoundOutput::playCallback(const void *input, void *output, unsigned long frameCount, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void *data)
{
    SoundOutput *newObj = static_cast<SoundOutput *>(data);

    if (newObj->_buffers.size() == 0)
        return paContinue;

    Sound::Decoded sound = newObj->getBuffers().front();
    float *new_ouput = static_cast<float *>(output);

    for (int i = 0; i < sound.size; i += 1)
        *new_ouput++ = sound.buffer[i];

    newObj->getBuffers().pop();

    return paContinue;
}

void SoundOutput::openStream()
{
    _err = Pa_OpenStream(
                &_stream,
                NULL,
                &_outputParameters,
                SAMPLE_RATE,
                FRAMES_PER_BUFFER,
                paClipOff,
                SoundOutput::playCallback,
                this);
    if (_err != paNoError)
        std::cerr << Pa_GetErrorText(_err) << std::endl;
}

void SoundOutput::startStream()
{
    _err = Pa_StartStream(_stream);
    if (_err != paNoError)
        std::cerr << Pa_GetErrorText(_err) << std::endl;
}

void SoundOutput::stopStream()
{
    if (_stream)
        _err = Pa_StopStream(_stream);
   if (_err != paNoError)
        std::cerr << Pa_GetErrorText(_err) << std::endl;
}