/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
# define FEDERATION_HPP_

#include <string>
#include "Destination.hpp"
#include "WarpSystem.hpp"

namespace Federation {
	namespace Starfleet {
		class Captain {
			public:
				Captain(std::string);
				~Captain();
				std::string getName();
				int	getAge();
				void setAge(int age);
			private:
				std::string _name;
				int _age;
		};
		class Ship {
			public:
				Ship(int, int, std::string, short);
				~Ship();
				void	setupCore(WarpSystem::Core *pointer);
				void	checkCore();
				void	promote(Federation::Starfleet::Captain *Captain);
				bool	move(int, Destination);
				bool	move(int);
				bool	move(Destination);
				bool	move(void);
			private:
				Destination	_location;
				Destination	_home;
				Federation::Starfleet::Captain	*_captain;
				WarpSystem::Core * _core;
				int	_lenght;
				int	_width;
				std::string	_name;
				short	_maxWarp;
		};
		class	Ensign {
			public:
				Ensign(std::string);
				~Ensign();
			private:
				std::string _name;
		};
	};
	class Ship {
		public:
			Ship(int, int, std::string);
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
			int	_lenght;
			int	_width;
			std::string	_name;
			short	_maxWarp;
	};
}



#endif /* !FEDERATION_HPP_ */
