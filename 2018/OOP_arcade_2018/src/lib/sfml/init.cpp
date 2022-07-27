/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** display
*/

#include "classSfml.hpp"

void SfmlLib::setInput()
{
    _input[sf::Keyboard::F2] = arcade::key::f2;
    _input[sf::Keyboard::F3] = arcade::key::f3;
    _input[sf::Keyboard::F4] = arcade::key::f4;
    _input[sf::Keyboard::F5] = arcade::key::f5;
    _input[sf::Keyboard::Enter] = arcade::key::enter;
    _input[sf::Keyboard::Escape] = arcade::key::escape;
    _input[sf::Keyboard::BackSpace] = arcade::key::backspace;
    _input[sf::Keyboard::Z] = arcade::key::z;
    _input[sf::Keyboard::Q] = arcade::key::q;
    _input[sf::Keyboard::S] = arcade::key::s;
    _input[sf::Keyboard::D] = arcade::key::d;
}

void SfmlLib::init(const arcade::state::state_t state)
{
    _win.create(sf::VideoMode(800, 600), "Arcade", sf::Style::Close | sf::Style::Titlebar);
    _run = true;
    setFont(&_text, &d_font, "ressources/font/font.ttf");
    setState(state);
    setKey(arcade::key::noaction);
    setInput();
}

void SfmlLib::doEvent(std::string &name)
{
    assignKey();
    if (_win.pollEvent(_event)) {
        if (_event.type == _event.Closed)
            _run = false;
        if (getKey() == arcade::key::escape)
            _run = false;
        if (this->getState() == arcade::state::Username)
            this->setName(name);
        else if (getState() == arcade::state::Menu &&
        getKey() == arcade::key::enter &&
        _event.type == sf::Event::TextEntered)
            setState(arcade::state::Game);
    }
}

void SfmlLib::clean()
{
    if (_win.isOpen())
        _win.clear();
}

void SfmlLib::assignKey()
{
    for (auto i : _input) {
        if (sf::Keyboard::isKeyPressed(i.first)) {
            setKey(i.second);
            return;
        }
    }
}

void SfmlLib::display()
{
    _win.display();
}

SfmlLib::~SfmlLib()
{
    if (_win.isOpen())
        _win.close();
}

extern "C"
{
    IDisplayModule *libEntry() {
        return (new SfmlLib());
    }
}