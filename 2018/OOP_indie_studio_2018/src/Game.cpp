/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** game
*/

#include "Game.hpp"
#include "SceneHandler.hpp"
#include "Sound.hpp"
#include "IA.hpp"

Game::Game(Core &core) : _core(core), _bombOnField(0), _map(STILE, 10, 10, _core.getDevice())
{
	_currentScene = GAME;
    _countPlayers = 0;
    _core._receiver = new EventReceiver(_core.getDevice(), _core.getDriver());
    _core.getDevice()->setEventReceiver(_core._receiver);
    if (_core.getDevice()->getEventReceiver() == nullptr) {
        throw std::invalid_argument("error game event receiver not setup");
    }
    createMap();
    createPlayers();
    loadComponents();
    start();
}

Game::~Game()
{
    for (std::list<Character *>::iterator it = _players.begin(); it != _players.end(); ++it) {
        (*it)->getPlayer()->remove();
        delete *it;
    }
    for (std::list<IA *>::iterator it = _ais.begin(); it != _ais.end(); ++it) {
        (*it)->getIA()->remove();
        delete *it;
    }
    _map.deleteMap();
    _map.deleteBonuses();
    for (auto i : _bomb)
        i.first->destroyAll();
}

void    Game::loadComponents(void)
{
    _map.setPlayer(_players);
    _map.setAis(_ais);
    _map.load(_mapVector, &_bonus);
    ILightSceneNode* light = _core.getSmgr()->addLightSceneNode(0, vector3df(200.0f, 2000.0f, 1200.0f), SColorf(1.0f, 1.0f, 1.0f, 1.0f), 8000.0f);

    light->getLightData().AmbientColor.set(1.0f, 1.0f, 1.0f, 1.0f);

    irr::core::vector3df camVec = _map.getMiddle();

    _cam = _core.getSmgr()->addCameraSceneNode(NULL,
            irr::core::vector3df(camVec.X - 20, STILE * 11, camVec.Z), camVec);

	_then = _core.getDevice()->getTimer()->getTime();
    _font = _core.getGUI()->getFont("./media/Menu/bigfont.png");
    _isGameOver = false;
}

void    Game::createPlayers(void)
{
    _playerType = _core.getPlayerType();
    if (_core.isLoaded() == true) {
        _players.clear();
        _playersInfo = _core.loadInfoPlayers();
        if (_playersInfo.front().speed == -42)
            _playersInfo.pop_front();
        _countPlayers = _playersInfo.front().nbPlayers;
        for (struct s_save s : _playersInfo) {
            _players.push_back(new Character(s.id, _core.stringToKeys(s.keys), s.pos, s.texturePath, _core));
            _players.front()->loadCharac(s);
        }
    } else {
        for (PlayerInfo *p : _playerType) {
            if (p->getBind().ai == true) {
                _ais.push_back(new IA(p->getId(), p->getPos(), p->getTexturePath(), _core));
            } else if (p->getBind().none == false) {
                _countPlayers += 1;
                _players.push_back(new Character(p->getId(), p->getBind(), p->getPos(), p->getTexturePath(), _core));
            }
        }
    }
}

void    Game::createMap(void)
{
    std::vector<std::string> tmp;

    if (_core.isLoaded() == true) {
        tmp = _core.loadInfoMap();
        for (auto a : tmp) {
            _mapVector.push_back(a);
        }
    } else {
        try { MapGen(); }
        catch (const std::vector<std::string> &map) {
            _mapVector = map;
        }
    }
}

void    Game::resetElapsedTime(void)
{
    _now = _core.getDevice()->getTimer()->getTime();
    _frameDeltaTime = (_now - _then) / 1000.f;
    _then = _now;
    return;
}

void    Game::putBomb(Character *player)
{
    if (_bombOnField == 0 || (_bombOnField > 0 && player->isIntoBomb() == false)) {
        if (player->getTempoBomb() == false) {
            _bomb.push_back(std::make_pair(new Bomb(_map.getTileMiddle(player->getPlayer()->getPosition()), player->getId(), _core, player->getPlayer()), _now + TIME_TO_EXPLODE));
            _bombOnField += 1;
            player->setBombLoad(-1);
            player->setIntoBomb(true);
            player->setTempoBomb(true);
        }
    }
    return;
}

void    Game::removeBomb(Character *player)
{
    for (auto i : _bomb) {
        if (_bomb.size() >= 1 && i.first->isBombExplosed() == false
            && (_now >= i.second) && _bombOnField >= 1) {
            if (player->getId() == i.first->getId()) {
                #ifndef WIN32
                    _sound.playBombExplosion();
                #endif
                i.first->getMesh()->remove();
                i.first->getPs()->remove();
                i.first->bombExplosion(_core, player->getPower());
                _bombOnField -= 1;
                player->setBombLoad(1);
            }
        }
    }
    if (_bomb.size() >= 1 && _bomb.front().first->isBombExplosed() == true
        && (_now >= _bomb.front().second + TIME_TO_FADE)) {
        _bomb.front().first->explosionFadeOut();
        _bomb.pop_front();
    }
    return;
}

void    Game::removeBombIA(IA *ia)
{
    for (auto i : _bomb) {
        if (_bomb.size() >= 1 && i.first->isBombExplosed() == false
            && (_now >= i.second)) {
            if (ia->getId() == i.first->getId()) {
                _sound.playBombExplosion();
                i.first->getMesh()->remove();
                i.first->getPs()->remove();
                i.first->bombExplosion(_core, ia->getPower());
                ia->setBombLoad(1);
            }
        }
    }
    if (_bomb.size() >= 1 && _bomb.front().first->isBombExplosed() == true
        && (_now >= _bomb.front().second + TIME_TO_FADE)) {
        _bomb.front().first->explosionFadeOut();
        _bomb.pop_front();
    }
    return;
}

void    Game::detectBombWithCubes(void)
{
    aabbox3d<f32> node1;
    aabbox3d<f32> node2;
    std::pair<int, int> at;
    int k = 0;

    for (auto c : _list) {
        node1 = c.first->getBoundingBox();
        c.first->getRelativeTransformation().transformBoxEx(node1);
        for (auto i : _bomb) {
            for (auto a : i.first->getExplosion()) {
                node2 = a->getBox();
                if (node1.intersectsWithBox(node2) == true) {
                    a->setCollider(true);
                    if (c.second == true) {
                        k = 1;
                        at = _map.getNode(c.first->getPosition());
                    }
                }
            }
        }
    }
    if (k == 1)
        _map[at]--;
}

struct s_save    Game::savePlayers(Character *player)
{
    struct s_save  info;

    info.keys = _core.keysToString(player->getBind());
    info.id = player->getId();
    info.nbPlayers = _countPlayers;
    info.isPlayer = 0;
    info.texturePath = player->getTexturePath();
    info.bomb_power = player->getPower();
    info.speed = player->getSpeed();
    info.nb_bombs = player->getBombLoad();
    info.pos = player->getPos();
    return info;
}

int Game::handlePlayers(std::list<struct s_save> &playersInfo, int pSurvivors)
{
    int isDead = -1;

    for (Character *player : _players) {
        player->findPosition();
        if (player->getAlive() == true && player->bombAction(_now, _core) == true) {
            putBomb(player);
        }
        removeBomb(player);
        player->pickUpBonus(_bonus, _core);
        player->rotate(_core);
        if (player->detectBombExplosion(_bomb, _core) == true)
            isDead = player->getId();
        if (player->getAlive() == true) {
            player->move(_frameDeltaTime, _core, _bomb, _map.getMapVector());
            playersInfo.push_back(savePlayers(player));
        }
        if (isDead == player->getId()) {
            isDead = -1;
            player->getPlayer()->setPosition(vector3df(0, -20, 0));
            player->setAlive(false);
        }
        if (player->getAlive() == false)
            pSurvivors -= 1;
    }
    return pSurvivors;
}

int    Game::handleIA(int time, int iaSurvivors)
{
    int isDead = -1;

    for (IA *ai : _ais) {
        if (time % 50 == 0)
            ai->setDirection(_map.getMapVector(), _core);
        ai->findPosition();
        if (ai->bombAction(_now, _core) == true)
            _bomb.push_back(std::make_pair(new Bomb(_map.getTileMiddle(ai->getIA()->getPosition()), ai->getId(), _core, ai->getIA()), _now + TIME_TO_EXPLODE));
        removeBombIA(ai);
        ai->pickUpBonus(_bonus, _core);
        if (ai->detectBombExplosion(_bomb, _core) == true)
            isDead = ai->getId();
        if (ai->getAlive() == true)
            ai->move(_frameDeltaTime, _core, _bomb, _map.getMapVector());
        if (isDead == ai->getId()) {
            isDead = -1;
            ai->getIA()->setPosition(vector3df(0, -20, 0));
            ai->setAlive(false);
        }
        if (ai->getAlive() == false)
            iaSurvivors -= 1;
    }
    return iaSurvivors;
}

void    Game::checkGameOver(void)
{
    if (_isGameOver == true) {
        for (Character *player : _players) {
            if (player->getAlive() == true) {
                _winner.assign("PLAYER ");
                if (player->getId() == 1)
                    _winner.append("RED");
                else if (player->getId() == 2)
                    _winner.append("BLUE");
                else if (player->getId() == 3)
                    _winner.append("GREEN");
                else if (player->getId() == 4)
                    _winner.append("PINK");
                _winner.append(" WIN");
            }
        }
        _font->draw(_winner.c_str(), core::recti(1920 / 2, 1080 / 2, 0, 0), video::SColor(255, 255, 255, 255));
        if (_now >= _backToMenu) {
            _core._receiver->changeScene(MENU);
            remove("save.txt");
        }
    }
}

void    Game::start(void)
{
    int time = 0;
    int pSurvivors = (int)_players.size();
    int iaSurvivors = (int)_ais.size();

    #ifndef WIN32
        _sound.playGameMusic();
    #endif
	while (_core.getDevice()->run() && _core._receiver->getScene() == GAME) {
        std::list<struct s_save>       playersInfo;
        time += 1;
        resetElapsedTime();
		_core.getDriver()->beginScene(true, true, SColor(255, 100, 101, 140));
        pSurvivors = handlePlayers(playersInfo, pSurvivors);
        iaSurvivors = handleIA(time, iaSurvivors);
        if (((pSurvivors <= 1 && iaSurvivors <= 0) || (pSurvivors <= 0 && iaSurvivors <= 1))&& _isGameOver == false) {
            _isGameOver = true;
            _backToMenu = _now + 2500;
        }
        _list = _map.getObjects();
        detectBombWithCubes();
        for (auto i : _bomb) {
            if (i.first->isBombExplosed() == true) {
                for (auto a : i.first->getExplosion())
                    a->updateExplosion();
            }
        }
        _core.getDriver()->draw2DImage(_core.getDriver()->getTexture("media/wtf.png"), core::position2d<s32>(0,0), core::rect<s32>(0,0,1920,1280), 0, video::SColor(255,255,255,255), true);
        _core.updateSave(_map.save(), playersInfo);
        _core.getDevice()->setEventReceiver(_core._receiver);
		_core.getSmgr()->drawAll();
        checkGameOver();
		_core.getDriver()->endScene();
	}
    if (_core._receiver->getScene() == IScene::SAVE_QUIT) {
        _core.save();
        changeScene(QUIT);
    } else if (_core._receiver->getScene() == IScene::SAVE_MENU) {
        _core.save();
        _core.clearSave();
        changeScene(MENU);
    } else
        changeScene(_core._receiver->getScene());
}