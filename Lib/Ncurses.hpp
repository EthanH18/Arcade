/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
    #define NCURSES_HPP_

#include <unistd.h>
#include <cmath>
#include <ncurses.h>

#include "../Lib/Object.hpp"
#include "../Lib/Text.hpp"
#include "ILib.hpp"

namespace Arcade {

    std::map<int, Arcade::Input> Key_list = {
		{27, Input::ESCAPE},
		{10, Input::ENTER},
		{'r', Input::RESTART},
		{'z', Input::UP},
		{'q', Input::LEFT},
		{'s', Input::DOWN},
		{'d', Input::RIGHT},
		{'m', Input::MENU},
		{KEY_F(4), Input::PREV_LIB},
		{KEY_F(5), Input::NEXT_LIB},
		{0404, Input::LEFT},
		{0405, Input::RIGHT},
		{0403, Input::UP},
		{0402, Input::DOWN},
        {'p', Input::PAUSE}
    };

    class Ncurses final : public AGraphic {
        public:
            Ncurses();
            ~Ncurses();
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
    };
    
    extern "C" Ncurses *entryPoint() {
        return new Ncurses;
    };

}

#endif /* !NCURSES_HPP_ */