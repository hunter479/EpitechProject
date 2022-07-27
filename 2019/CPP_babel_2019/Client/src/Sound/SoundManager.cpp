/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** SoundManager
*/

#include "SoundManager.hpp"
#include "PortAudioM.hpp"
#include "Opus.hpp"

// SoundManager *SoundManager::_audioM = 0;

// SoundManager::SoundManager()
// {
//     std::cout << "test" << std::endl;
    // _soundDeviceM = new PortAudioM;
    // _encodeM = new Opus;
// }

// SoundManager::~SoundManager()
// {
    // if (_soundDeviceM)
    //     delete _soundDeviceM;
    // if (_encodeM)
    //     delete _encodeM;
// }

// Input Stream

// void SoundManager::startRecording() const
// {
//     _soundDeviceM->getInput()->startStream();
// }

// void SoundManager::stopRecording() const
// {
//     _soundDeviceM->getInput()->stopStream();
// }

// Output Stream

// void SoundManager::startPlaying() const
// {
//     _soundDeviceM->getOutput()->startStream();
// }

// void SoundManager::stopPlaying() const
// {
//     _soundDeviceM->getOutput()->stopStream();
// }

// SoundManager *SoundManager::getInstance()
// {
//     if (_audioM == nullptr)
//         _audioM = new SoundManager();
//     return _audioM;
// }

// void SoundManager::soundIsAvailable() const
// {
//     // sendEncodedSound();
//     // receiveDecodedSound();

//     Sound::Decoded sound;

//     if (_soundDeviceM->getInput()->getBuffers().size() != 0) {
//         Sound::Decoded soundCpy = _soundDeviceM->getInput()->getBuffers().front();

//         sound.buffer = soundCpy.buffer;
//         sound.size = soundCpy.size;

//         _soundDeviceM->getInput()->getBuffers().pop();
//     } else
//         sound.size = 0;

//     Sound::Encoded encoded;
//     encoded = _encodeM->encode(sound);

//     Sound::Decoded decoded;
//     decoded = _encodeM->decode(encoded);

//     if (decoded.size != 0)
//         _soundDeviceM->getOutput()->getBuffers().push(decoded);
// }

// void SoundManager::sendEncodedSound() const
// {
//     Sound::Decoded sound;

//     if (_soundDeviceM->getInput()->getBuffers().size() != 0) {
//         Sound::Decoded soundCpy = _soundDeviceM->getInput()->getBuffers().front();

//         sound.buffer = soundCpy.buffer;
//         sound.size = soundCpy.size;

//         _soundDeviceM->getInput()->getBuffers().pop();
//     } else
//         sound.size = 0;

//     Sound::Encoded encoded;
//     encoded = _encodeM->encode(sound);

//     // emit encoded sound
// }

// void SoundManager::receiveDecodedSound() const
// {
//     Sound::Encoded encoded;
//     // encoded =  receive encoded sound

//     Sound::Decoded decoded;
//     // decoded = _encodeM->decode(/* encoded sound */);

//     if (decoded.size != 0)
//         _soundDeviceM->getOutput()->getBuffers().push(decoded);
// }
