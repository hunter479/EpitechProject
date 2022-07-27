/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
	#define WARPSYSTEM_HPP_

namespace WarpSystem {
	class QuantumReactor {
		public:
			QuantumReactor();
			~QuantumReactor();
			bool	isStable();
			void    setStability(bool stability);
		private:
			bool _stability;
	};
	class Core {
		public:
			Core(QuantumReactor *);
			QuantumReactor *checkReactor(void);
		private:
			QuantumReactor *_coreReactor;
	};
}

#endif /* !WARPSYSTEM_HPP_ */
