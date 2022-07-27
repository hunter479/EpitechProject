/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** Parser
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

#include <string>

class Parser {
	public:
		Parser() {_result = 0;};
		~Parser() {};
        void feed(const std::string &);
        int result () const {return (_result);};
        void reset() {_result = 0;};
	protected:
	private:
        int _result;
};

#endif /* !PARSER_HPP_ */
