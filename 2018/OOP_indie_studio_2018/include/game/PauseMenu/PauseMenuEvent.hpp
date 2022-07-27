/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** PauseMenuEvent
*/

#ifndef PAUSEMENUEVENT_HPP_
#define PAUSEMENUEVENT_HPP_

#include "irrlicht.h"

class PauseMenuEvent : public irr::IEventReceiver {
	public:
        enum status {
            RESUME, QUIT, MENU, RUN
        };
		PauseMenuEvent();
		~PauseMenuEvent();
        virtual bool OnEvent(const irr::SEvent &event);
        const status getStatus() const;
	protected:
	private:
        status _current;
        bool button_event(irr::s32 id);
		bool keyboard_event(const irr::SEvent &event);
};

#endif /* !PAUSEMENUEVENT_HPP_ */
