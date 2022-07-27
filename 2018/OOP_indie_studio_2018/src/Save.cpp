/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Save
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include "Save.hpp"

Save::Save()
{
    struct s_save  default_save;

    default_save.nbPlayers = 0;
    default_save.isPlayer = false;
    default_save.bomb_power = 0;
    default_save.speed = -42;
    default_save.nb_bombs = 4;
    default_save.pos = vector3df(0, 0, 0);
    _players.push_back(default_save);
    _map.push_back("XXXXXXXXXX");
    _map.push_back("XXXXXXXXXX");
    _map.push_back("XXXXXXXXXX");
    _map.push_back("XXXXXXXXXX");
    _map.push_back("XXXXXXXXXX");
    _map.push_back("XXXXXXXXXX");
    _map.push_back("XXXXXXXXXX");
    _map.push_back("XXXXXXXXXX");
    _map.push_back("XXXXXXXXXX");
    _map.push_back("XXXXXXXXXX");
}

Save::~Save()
{
}

vector3df   Save::getVectorPos(std::string &vec)
{
    vector3df pos;

    try {
        size_t c = vec.find_first_of(' ', 0);
        pos.X = std::stof(vec.substr(0, c));
        vec.erase(0, c + 1);
        c = vec.find_first_of(' ', 0);
        pos.Y = std::stof(vec.substr(0, c));
        vec.erase(0, c + 1);
        c = vec.find_first_of(' ', 0);
        pos.Z = std::stof(vec.substr(0, c));
        vec.erase(0, c + 1);
    } catch (const std::exception & excep) {
        throw excep;
    }
    return pos;
}

bool    Save::setInfoPlayer(std::ifstream &myfile)
{
    struct s_save  current;
    std::string line;
    std::vector<std::string> tmp;

    try {
        std::getline(myfile, line);
        int i = 0;
        while (line.c_str() && line.compare("===== END =====") != 0) {
            tmp.push_back(line);
            getline(myfile, line);
            i += 1;
        }
        if (line.compare("===== END =====") != 0 && i != 5)
            return false;
        current.nbPlayers = _nbPlayers;
        current.pos = getVectorPos(tmp.at(4));
        current.id = std::stoi(tmp.at(6));
        current.isPlayer = std::stoi(tmp.at(0));
        current.bomb_power = std::stoi(tmp.at(1));
        current.speed = std::stoi(tmp.at(2));
        current.nb_bombs = std::stoi(tmp.at(3));
        current.texturePath = tmp.at(5);
        current.keys = tmp.at(7);
        _players.push_back(current);
        return true;
    } catch (const std::exception & excep) {
        throw excep;
    }
}

bool    Save::setInfoMap(std::ifstream &myfile)
{
    try {
        std::string line;
        std::getline(myfile, line);
        while (line.c_str() && line.compare("===== END =====") != 0) {
            _map.push_back(line);
            getline(myfile, line);
        }
        if (line.compare("===== END =====") != 0)
            return false;
        return true;
    } catch (const std::exception & excep) {
        throw excep;
    }
}

void    Save::cleanSave(void)
{
    for (struct s_save p : _players) {
        p.pos = vector3df(0, 0, 0);
        p.bomb_power = 0;
        p.speed = 0;
        p.nb_bombs = 0;
        p.isPlayer = false;
    }
    _map.clear();
}

bool    Save::verifFile(void)
{
    std::ifstream myfile("./save.txt");
    std::string line;

    int i = 1;
    cleanSave();
    bool ret = true;
    try {
        if (myfile.is_open()) {
            std::getline(myfile, line);
            _nbPlayers = stoi(line);
            while (std::getline(myfile, line)) {
                std::string ai = "===== AI " + std::to_string(i) + " =====";
                std::string player = "===== PLAYER " + std::to_string(i) + " =====";
                if (line.compare(ai) == 0 || line.compare(player) == 0) {
                    ret = setInfoPlayer(myfile);
                    i += 1;
                } else if (line.compare("===== MAP =====") == 0)
                    ret = setInfoMap(myfile);
                if (ret == false)
                    return false;
            }
            myfile.close();
        } else {
            return false;
        }
        return true;
    } catch (const std::exception &excep) {
        std::cerr << "Error in save file, aborting" << std::endl;
    }
    return false;
}

void    Save::clearAll(void)
{
    _players.clear();
}

void	Save::createFile(void)
{
	int	i = 1;

    remove("save.txt");
	std::ofstream file ("save.txt");
    if (_players.size() > 0) {
        file << _players.front().nbPlayers << std::endl;
        for (auto player : _players) {
            if (player.isPlayer == false)
                file << "===== AI " << i << " =====" << std::endl;
            else {
                file << "===== PLAYER " << i << " =====" << std::endl;
            }
            file << player.isPlayer << std::endl;
            file << player.bomb_power << std::endl;
            file << player.speed << std::endl;
            file << player.nb_bombs << std::endl;
            file << player.pos.X << " " << player.pos.Y << " " << player.pos.Z << " " << std::endl;
            file << player.texturePath << std::endl;
            file << player.id << std::endl;
            file << player.keys << std::endl;
            file << "===== END =====" << std::endl << std::endl;
            i += 1;
        }
    }
	file << "===== MAP =====" << std::endl;
	for (auto map : _map) {
        std::cout << "MAP: " << map << std::endl;
		file << map << std::endl;
	}
    file << "===== END =====" << std::endl;
    file.close();
	#ifndef WIN32
        chmod("./save.txt", S_IRUSR);
	#endif
}

void    Save::saveMap(const std::vector<std::string> &map)
{
    _map.clear();
    _map = map;
}

void    Save::saveCharacters(const std::list<struct s_save> &info)
{
    _players = info;
}

void    Save::display(void)
{
    for (int i = 0; i != (int)_map.size(); i ++)
        std::cout << _map.at(i) << std::endl;
    for(auto i : _players) {
        std::cout << i.isPlayer << std::endl;
        std::cout << i.bomb_power << std::endl;
        std::cout << i.speed << std::endl;
        std::cout << i.nb_bombs << std::endl;
        std::cout << i.pos.X << " " << i.pos.Y << " " << i.pos.Z << " " << std::endl;
    }
}