/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** draw
*/

#include <unistd.h>
#include "classSfml.hpp"

void SfmlLib::updateBg()
{
    if (_state == arcade::state::Username)
        setSprite(&b_texture, &b_sprite, "ressources/Username/background.png");
    else if (_state == arcade::state::Menu)
        setSprite(&b_texture, &b_sprite, "ressources/Menu/background.png");
    else if (_state == arcade::state::Game)
        setSprite(&b_texture, &b_sprite, "ressources/Game/background.png");
    _win.draw(b_sprite);
}

void SfmlLib::drawMap(const std::vector<std::string> &map)
{
    size_t i = 0;
    int pos = 0;
    float x = 0;
    float y = 0;

    while (i < map.size()) {
        pos = 0;
        while (map.at(i).c_str()[pos] != '\0') {
            s_block.setPosition(x, y);
            if (map.at(i).c_str()[pos] != ' ') {
                if (map.at(i).c_str()[pos] == '*')
                    setSprite(&t_block, &s_block, "ressources/Game/block.png");
                else if (map.at(i).c_str()[pos] == 'P')
                    setSprite(&t_block, &s_block, "ressources/Game/player.png");
                _win.draw(s_block);
            }
            x += 40;
            pos++;
        }
        x = 0;
        y += 40;
        i += 1;
    }
}

void SfmlLib::drawList(const std::vector<std::string> &s)
{
    float y = 250;
    size_t i = 0;

    while (s.size() > i) {
        _text.setPosition(50, y);
        _text.setString(s.at(i));
        _win.draw(_text);
        i++;
        y += 30;
    }
}

void SfmlLib::draw(const std::vector<std::string> &list)
{
    updateBg();
    if (getState() == arcade::state::Username)
        _win.draw(_text);
    if (getState() == arcade::state::Menu)
        drawList(list);
    if (getState() == arcade::state::Game) {
        drawMap(list);
        usleep(60000);
    }
}
