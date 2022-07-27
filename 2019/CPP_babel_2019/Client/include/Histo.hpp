/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** Histo
*/

#ifndef HISTO_HPP_
#define HISTO_HPP_

#include <vector>
#include <string>
#include <boost/serialization/access.hpp>

class Histo {
	public:
		Histo() {}
		~Histo() {}

        private:
        friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive &ar, const unsigned int version){
			ar & _histo;
		}


    public:
        std::string getHisto(const std::string &);
        std::string uploadHisto(const std::string &);
        void    push_message_back(std::string message) { _histo.push_back(message); }
        const std::vector<std::string> &getMessage(void) { return _histo; }

	private:
        std::vector<std::string> _histo;
};

#endif /* !HISTO_HPP_ */
