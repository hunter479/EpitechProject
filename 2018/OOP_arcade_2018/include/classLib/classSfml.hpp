/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** classSfml
*/

#ifndef CLASSSFML_HPP_
    #define CLASSSFML_HPP_

#include <SFML/Graphics.hpp>
#include "IDisplayModule.hpp"

class SfmlLib : public IDisplayModule
{
    public:
        SfmlLib() {};
        virtual ~SfmlLib();
        void doEvent(std::string &);
        void clean();
        bool isOpen() const {return (_run);};
        void display();

        void init(const arcade::state::state_t);
        void stop();

        const arcade::state::state_t &getState() const {return (_state);};
        const arcade::key::key_t &getKey() const {return (_key);};
        void setState(const arcade::state::state_t &e) {_state = e;};
        void setKey(const arcade::key::key_t e) {_key = e;};
        void setName(std::string &);
        void setInput();

        void draw(const std::vector<std::string> &);
    private:
        void drawList(const std::vector<std::string> &);
        void drawMap(const std::vector<std::string> &map);
        void assignKey();
        void updateBg();
        void handleState();

    private:
        bool _run = false;
        arcade::state::state_t _state;
        arcade::key::key_t _key;

        sf::RenderWindow _win;
        sf::Event _event;

        sf::Text _text;
        sf::Texture t_block;
        sf::Sprite s_block;

        sf::Font d_font;
        // background
        sf::Texture b_texture;
        sf::Sprite b_sprite;

        std::map<sf::Keyboard::Key, arcade::key::key_t> _input;
};

void setSprite(sf::Texture *, sf::Sprite *, const char *);
void setFont(sf::Text *, sf::Font *, const char *);

#endif /* !CLASSSFML_HPP_ */
