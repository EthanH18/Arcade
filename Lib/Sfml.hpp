/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** sfml.hpp
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

#include <iostream>
#include <thread>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../Lib/Object.hpp"
#include "../Lib/Text.hpp"
#include "ILib.hpp"
#include "unistd.h"

namespace Arcade {

    std::map<Arcade::Color, sf::Color> sfmlColor {
        {Arcade::Color::BLACK, sf::Color::Black},
        {Arcade::Color::RED, sf::Color::Red},
        {Arcade::Color::GREEN, sf::Color::Green},
        {Arcade::Color::YELLOW, sf::Color::Yellow},
        {Arcade::Color::BLUE, sf::Color::Blue},
        {Arcade::Color::MAGENTA, sf::Color::Magenta},
        {Arcade::Color::CYAN, sf::Color::Cyan},
        {Arcade::Color::WHITE, sf::Color::White}
    };

    std::map<sf::Keyboard::Key, Arcade::Input> Key_list = {
		{sf::Keyboard::Escape, Input::ESCAPE},
		{sf::Keyboard::Enter, Input::ENTER},
		{sf::Keyboard::R, Input::RESTART},
		{sf::Keyboard::Z, Input::UP},
		{sf::Keyboard::Q, Input::LEFT},
		{sf::Keyboard::S, Input::DOWN},
		{sf::Keyboard::D, Input::RIGHT},
        {sf::Keyboard::M, Input::MENU},
		{sf::Keyboard::F4, Input::PREV_LIB},
		{sf::Keyboard::F5, Input::NEXT_LIB},
		{sf::Keyboard::Left, Input::LEFT},
		{sf::Keyboard::Right, Input::RIGHT},
		{sf::Keyboard::Up, Input::UP},
		{sf::Keyboard::Down, Input::DOWN},
        {sf::Keyboard::P, Input::PAUSE}
	};
    class Sfml final : public AGraphic {
        public:
            Sfml();
            ~Sfml();
            void createWindow() override;
            void drawObject(Arcade::Object *) override;
            void drawBackground(std::string) override;
            void clear();
            void drawText(Arcade::Text *) override;
            void draw(std::shared_ptr<Arcade::IObject> obj);
            Arcade::Input getEvent() override;
            void update();
        protected:
        private:
            sf::RenderWindow _wndw{};
            sf::Font _font{};
            sf::Texture _txture{};
    };

    extern "C" Sfml *entryPoint() {
        return new Sfml;
    };
}

#endif /* !SFML_HPP_ */
