/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** setName
*/

#include <string>
#include <iostream>
#include <unistd.h>
#include "classSfml.hpp"

void setSprite(sf::Texture *texture, sf::Sprite *sprite, const char *path)
{
    if (texture->loadFromFile(path) == false)
        throw std::invalid_argument("texture not loaded");
    sprite->setTexture(*texture);
}

void setFont(sf::Text *text, sf::Font *font, const char *f_path)
{
    if (font->loadFromFile(f_path) == false)
        throw std::invalid_argument("font not loaded");
    text->setFont(*font);
    text->setFillColor(sf::Color::White);
    text->setCharacterSize(36);
}

void SfmlLib::setName(std::string &name)
{
    _text.setPosition(180, 140);
    if (_event.type == sf::Event::TextEntered) {
        char c = (char)_event.text.unicode;
        if (getKey() == arcade::key::enter)
            this->setState(arcade::state::Menu);
        else if (getKey() == arcade::key::backspace && name.size() > 0)
            name.pop_back();
        else if (getKey() == arcade::key::noaction ||
        (getKey() >= arcade::key::z && getKey() <= arcade::key::d))
            name.push_back(c);
        _text.setString(name);
    }
}