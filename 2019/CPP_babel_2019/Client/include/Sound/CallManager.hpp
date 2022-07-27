/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** CallManager
*/

#ifndef CALLMANAGER_HPP_
#define CALLMANAGER_HPP_

#include <QtNetwork/QUdpSocket>
#include <QByteArray>
#include <QHostAddress>
#include <QString>
#include "ISoundDevice.hpp"
#include "ICodec.hpp"

class CallManager {
	public:
		~CallManager();

		void startCall(QUdpSocket *, int, const std::string &);
		void stopCall() const;

		static CallManager *getInstance();

        void soundIsAvailable() const;
		void receiveDecodedSound(std::string);

	private:
		CallManager();
		int					_port;
		std::string			_ip;
		static CallManager *_callM;
		ISoundDevice	*_soundDeviceM;
		ICodec			*_encodeM;

		QUdpSocket		*_socket;
};

#endif /* !CALLMANAGER_HPP_ */
