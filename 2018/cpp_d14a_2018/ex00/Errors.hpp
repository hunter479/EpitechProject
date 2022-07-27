/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
    #define ERRORS_HPP_

#include <exception>
#include <string>

class NasaError : virtual public std::exception
{
    public:
        NasaError(std::string const &message, std::string const &component = "Unknown");
        virtual ~NasaError() noexcept {};
        const char *what() const noexcept override {return (_message.c_str());};
        std::string const &getComponent() const {return (_component);};

    protected:
        std::string _component;
        std::string _message;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message, std::string const &component = "MissionCriticalError") : NasaError(message, component) {};
        ~MissionCriticalError() {};
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message, std::string const &component = "LifeCriticalError") : NasaError(message, component) {};
        ~LifeCriticalError() {};
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message, std::string const &component = "UserError") : NasaError(message, component) {};
        ~UserError() {};
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message) : NasaError(message, "CommunicationError") {};
        ~CommunicationError() {};
};

#endif
