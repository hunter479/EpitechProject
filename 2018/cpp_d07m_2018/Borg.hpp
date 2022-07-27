/*
** EPITECH PROJECT, 2019
** cpp_d07m_2018
** File description:
** Bord
*/

#ifndef BORG_HPP_
	#define BORG_HPP_

#include <iostream>
#include "Destination.hpp"
#include "WarpSystem.hpp"

namespace Borg {
    class Ship {
		public:
			Ship();
			~Ship();
			void	setupCore(WarpSystem::Core *pointer);
			void	checkCore();
			bool	move(int, Destination);
			bool	move(int);
			bool	move(Destination);
			bool	move(void);
		private:
			Destination	_location;
			Destination	_home;
			WarpSystem::Core * _core;
            int _side;
			int	_lenght;
			short	_maxWarp;
    };
}

#endif /* !BORG_HPP_ */
