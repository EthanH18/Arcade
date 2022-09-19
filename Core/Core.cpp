/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-ethan.hayot
** File description:
** Core
*/

#include <iostream>
#include <filesystem>
#include <experimental/filesystem>
#include <string>

#include "Core.hpp"

void Arcade::Core::init_menu()
{
    int i = 0;
    while (i < _grphlibs.size())
    {
        if (i != _grphit)
            _menu.addLib(std::make_shared<Arcade::Text>(_grphlibs[i], Arcade::Color::WHITE, 350.f, 515.f + (float)(i * 50)));
        else
            _menu.addLib(std::make_shared<Arcade::Text>(_grphlibs[i], Arcade::Color::RED, 350.f, 515.f + (float)(i * 50)));
        i++;
    }
    _menu.addLib(std::make_shared<Arcade::Text>("LIBRARIES :", Arcade::Color::WHITE, 400.f, 400.f));
    _menu.addGame(std::make_shared<Arcade::Text>("PRESS ENTER TO PLAY :", Arcade::Color::CYAN, 900.f, 400.f));
}

void Arcade::Core::move_menu(Arcade::Input event)
{
    if (event == Arcade::Input::PREV_LIB)
        display_prev();
    else if (event == Arcade::Input::ENTER)
    {
        _game.Dynamic_loader(_gamelibs[_gmsit]);
        setScore();
        _is_menu = false;
    }
    else if (event == Arcade::Input::NEXT_LIB)
        display_next();
}

Arcade::Core::Core(std::string &pathname) : _path(pathname)
{
    namespace fs = std::experimental::filesystem;

    for (const auto &entry : fs::directory_iterator("./lib"))
    {
        if (entry.path().string().compare("./lib/.gitkeep") != 0)
        {
            _liball.Dynamic_loader(entry.path());
            if (_liball.getInstance()->getName().compare("IGraphic") == 0)
                _grphlibs.emplace_back(entry.path().string());
            else if (_liball.getInstance()->getName().compare("IGames") == 0)
                _gamelibs.emplace_back(entry.path().string());
        }
    }
    init_menu();
    _display.Dynamic_loader(_grphlibs[_grphit]);
    std::cout << "Enter your name: " << std::flush;
    std::getline(std::cin, _name);
    _is_menu = true;
    core_loop();
}

void Arcade::Core::change_lib(Arcade::Input &input)
{
    if (input == Arcade::Input::RESTART)
        _game.Dynamic_loader(_gamelibs[_gmsit]);
    if (input == Arcade::Input::PREV_LIB)
        display_prev();
    if (input == Arcade::Input::NEXT_LIB)
        display_next();
}

void Arcade::Core::menu_draw(std::string path)
{
    _display.getInstance()->clear();
    _display.getInstance()->drawBackground(path);
    auto temp = _menu.getMenu();

    for (auto &tmp : temp)
        _display.getInstance()->draw(tmp);
    auto temp1 = _menu.getLib();
    if (_is_menu == true)
    {
        for (auto &tmp : temp1)
            _display.getInstance()->draw(tmp);
        auto temp2 = _menu.getGame();
        for (auto &tmp : temp2)
            _display.getInstance()->draw(tmp);
    }
}

void Arcade::Core::display_next()
{
    if (_grphlibs.size() <= 1)
        return;
    _grphit = (_grphit + 1) % _grphlibs.size();
    _display.Dynamic_loader(_grphlibs[_grphit]);
    _display.getInstance()->createWindow();
    _menu.getLib()[_grphit]->setColor(Arcade::Color::RED);
    _menu.getLib()[(_grphit - 1) % _grphlibs.size()].get()->setColor(Arcade::Color::WHITE);
}

void Arcade::Core::setScore()
{
    _score.setPath(_gamelibs[_gmsit].substr(
                       _gamelibs[_gmsit].find_last_of("/\\") + 1,
                       _gamelibs[_gmsit].find_last_of(".so")) +
                   ".txt");
    _score.loadScore();
}

void Arcade::Core::best_score()
{
    if (_score.getScore().compare("NOT AVAILABLE") != 0)
        _best_score.get()->setText(_score.getName() + " " + _score.getScore());
    else
        _best_score.get()->setText("NOT AVAILABLE");
    _display.getInstance()->draw(_best_score);
}

void Arcade::Core::display_prev()
{
    if (_grphlibs.size() <= 1)
        return;
    if (_grphit == 0)
        _grphit = _grphlibs.size() - 1;
    else
        _grphit = (_grphit - 1) % _grphlibs.size();
    _display.Dynamic_loader(_grphlibs[_grphit]);
    _display.getInstance()->createWindow();
    _menu.getLib()[_grphit]->setColor(Arcade::Color::RED);
    _menu.getLib()[(_grphit + 1) % _grphlibs.size()].get()->setColor(Arcade::Color::WHITE);
}

void Arcade::Core::endGame()
{
    if (_game.getInstance()->endGame() == true)
    {
        _score.writeScore(_name, std::to_string(_game.getInstance()->getScore()));
        _game.Dynamic_loader(_gamelibs[_gmsit]);
    }
}

void Arcade::Core::core_loop()
{
    _display.getInstance()->createWindow();

    for (Arcade::Input input = _display.getInstance()->getEvent(); input != Arcade::Input::ESCAPE; input = _display.getInstance()->getEvent())
    {
        if (input == Arcade::Input::MENU)
            _is_menu = true;
        else if (_is_menu == true)
        {
            move_menu(input);
            menu_draw("assets/menu.png");
            _display.getInstance()->update();
        }
        else
        {
            endGame();
            change_lib(input);
            menu_draw("assets/background.jpg");
            best_score();
            auto buff = _game.getInstance()->play(input);
            for (auto &tmp : buff)
                _display.getInstance()->draw(tmp);
            _display.getInstance()->update();
        }
    }
    _display.getInstance()->clear();
}