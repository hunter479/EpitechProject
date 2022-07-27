/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** CallManager
*/

#include "Serial.hpp"
#include "CallManager.hpp"
#include "PortAudioM.hpp"
#include "Serial.hpp"
#include "Opus.hpp"

CallManager *CallManager::_callM = 0;

CallManager::CallManager()
{
    _soundDeviceM = new PortAudioM;
    _encodeM = new Opus;
}

CallManager::~CallManager()
{
    if (_callM)
        delete _callM;
    if (_soundDeviceM)
        delete _soundDeviceM;
    if (_encodeM)
        delete _encodeM;
}

CallManager *CallManager::getInstance()
{
    if (_callM == nullptr)
        _callM = new CallManager();
    return _callM;
}

void CallManager::startCall(QUdpSocket *socket, int port, const std::string &ip)
{
    _socket = socket;
    _port = port;
    _ip = ip;

    _soundDeviceM->getInput()->openStream();
    _soundDeviceM->getInput()->startStream();

    _soundDeviceM->getOutput()->openStream();
    _soundDeviceM->getOutput()->startStream();
}

void CallManager::stopCall() const
{
    _soundDeviceM->getInput()->stopStream();
    _soundDeviceM->getOutput()->stopStream();
    _socket->readAll();
}

void CallManager::soundIsAvailable() const
{
    Sound::Decoded soundCpy;

    if (_soundDeviceM->getInput()->getBuffers().size() != 0) {
        soundCpy = _soundDeviceM->getInput()->getBuffers().front();
        _soundDeviceM->getInput()->getBuffers().pop();
    } else
        soundCpy.size = 0;

    Sound::Encoded encoded;
    encoded = _encodeM->encode(soundCpy);

    std::string serialized = Serial::save(encoded);

    QByteArray data;
    QHostAddress addr;

    addr.setAddress(_ip.c_str());
    data.append(serialized.c_str());
    _socket->writeDatagram(data, addr, _port);
}

void CallManager::receiveDecodedSound(std::string data)
{
    Sound::Encoded deserialized = Serial::load<Sound::Encoded>(data);

    Sound::Decoded decoded;
    decoded = _encodeM->decode(deserialized);

    if (decoded.size != 0)
        _soundDeviceM->getOutput()->getBuffers().push(decoded);
}
