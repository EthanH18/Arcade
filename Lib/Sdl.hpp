/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** sdl.hpp
*/

#ifndef SDL_HPP_
    #define SDL_HPP_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_audio.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "../Lib/Object.hpp"
#include "../Lib/Text.hpp"
#include "ILib.hpp"

namespace Arcade {

    std::map<Arcade::Color, SDL_Color> sdlColor {
        {Arcade::Color::BLACK, {0, 0, 0, 0}},
        {Arcade::Color::BLUE, {0, 0, 255, 0}},
        {Arcade::Color::RED, {255, 0, 0, 0}},
        {Arcade::Color::GREEN, {0, 255, 0, 0}},
        {Arcade::Color::YELLOW, {255, 255, 0, 0}},
        {Arcade::Color::MAGENTA, {255, 0, 255, 0}},
        {Arcade::Color::CYAN, {0, 255, 255, 0}},
        {Arcade::Color::WHITE, {255, 255, 255, 0}},
    };
    std::map<SDL_Keycode, Arcade::Input> Key_list = {
		{SDLK_ESCAPE, Input::ESCAPE},
		{SDLK_RETURN, Input::ENTER},
		{SDLK_r, Input::RESTART},
		{SDLK_z, Input::UP},
		{SDLK_q, Input::LEFT},
		{SDLK_s, Input::DOWN},
		{SDLK_d, Input::RIGHT},
		{SDLK_m, Input::MENU},
		{SDLK_F4, Input::PREV_LIB},
		{SDLK_F5, Input::NEXT_LIB},
		{SDLK_LEFT, Input::LEFT},
		{SDLK_RIGHT, Input::RIGHT},
		{SDLK_UP, Input::UP},
		{SDLK_DOWN, Input::DOWN},
        {SDLK_p, Input::PAUSE}
	};

    class Sdl final : public AGraphic {
        public:
            Sdl();
            ~Sdl();
            Sdl(const Sdl&) = delete;
            Sdl& operator=(const Sdl&) = delete;
            Sdl(Sdl &&) = delete;
            Sdl& operator=(Sdl &&) = delete;
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
            SDL_Window *_wndw;
            SDL_Renderer *_render;
            TTF_Font *_font;
    };

    extern "C" Sdl *entryPoint() {
        return new Sdl;
    };

}

#endif /* !SDL_HPP_ */