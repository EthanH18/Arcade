/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

#include <vector>

#include "../Lib/Object.hpp"
#include "../Lib/Text.hpp"

namespace Arcade {

    class Menu {
        public:
            Menu() {
                _menu.emplace_back(std::make_shared<Arcade::Text>("HIGH SCORE", Arcade::Color::CYAN, 1550.f, 50.f));
                _menu.emplace_back(std::make_shared<Arcade::Text>("CONTROLS :", Arcade::Color::CYAN, 1320.f, 400.f));
                _menu.emplace_back(std::make_shared<Arcade::Text>("PRESS R TO RESTART THE GAME", Arcade::Color::CYAN, 1320.f, 465.f));
                _menu.emplace_back(std::make_shared<Arcade::Text>("PRESS M TO GO BACK TO THE MENU", Arcade::Color::CYAN, 1320.f, 515.f));
                _menu.emplace_back(std::make_shared<Arcade::Text>("PRESS ENTER TO START THE GAME", Arcade::Color::CYAN, 1320.f, 565.f));
                _menu.emplace_back(std::make_shared<Arcade::Text>("PRESS ESCAPE TO QUIT ARCADE", Arcade::Color::CYAN, 1320.f, 615.f));
                _menu.emplace_back(std::make_shared<Arcade::Text>("PRESS F4 TO SWITCH TO THE PREVIOUS LIBRARY", Arcade::Color::CYAN, 1320.f, 665.f));
                _menu.emplace_back(std::make_shared<Arcade::Text>("PRESS F5 TO SWITCH TO THE NEXT LIBRARY", Arcade::Color::CYAN, 1320.f, 715.f));
                _menu.emplace_back(std::make_shared<Arcade::Text>("PRESS P TO PAUSE THE GAME", Arcade::Color::CYAN, 1320.f, 865.f));
            };
            ~Menu() = default;
            void addObj(std::shared_ptr<Arcade::IObject> text) {
                _menu.emplace_back(text);
            }
            void addLib(std::shared_ptr<Arcade::Text> text) {
                _lib.emplace_back(text);
            }
            void addGame(std::shared_ptr<Arcade::Text> text) {
                _game.emplace_back(text);
            }
            std::vector<std::shared_ptr<Arcade::IObject>> getMenu() {
                return _menu;
            };
            std::vector<std::shared_ptr<Arcade::Text>> getLib() {
                return _lib;
            };
            std::vector<std::shared_ptr<Arcade::Text>> getGame() {
                return _game;
            };
        private:
            std::vector<std::shared_ptr<Arcade::IObject>> _menu;
            std::vector<std::shared_ptr<Arcade::Text>> _lib;
            std::vector<std::shared_ptr<Arcade::Text>> _game;
    };
}

#endif /* !MENU_HPP_ */
