/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** sdl.cpp
*/

#include "Sdl.hpp"

void Arcade::Sdl::createWindow()
{
    if (!_font)
        throw ErrorGame("Failed to load font");
    _wndw = SDL_CreateWindow( "Arcade {SDL}", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN );
    _render = SDL_CreateRenderer(_wndw, -1, SDL_RENDERER_ACCELERATED);
}

Arcade::Sdl::Sdl()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    _wndw = nullptr;
    _render = nullptr;
    _font = TTF_OpenFont("assets/font.ttf", 25);
}

Arcade::Sdl::~Sdl()
{
    
    if (_render != nullptr)
        SDL_DestroyRenderer(_render);
    if (_wndw != nullptr)
        SDL_DestroyWindow(_wndw);
    TTF_CloseFont(_font);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

void Arcade::Sdl::drawObject(Arcade::Object *obj)
{
    SDL_Surface *surface = IMG_Load(obj->getPath().c_str());
    SDL_Texture *temp = SDL_CreateTextureFromSurface(_render, surface);
    SDL_Rect rect {};

    rect.w = 1 * 15;
    rect.h = 1 * 20;
    rect.x = 600 + obj->getPos().first * 15;
    rect.y = 365 + obj->getPos().second * 20;
    SDL_RenderCopy(_render, temp, NULL, &rect);
    SDL_DestroyTexture(temp);
    SDL_FreeSurface(surface);
}

void Arcade::Sdl::drawBackground(std::string path)
{
    SDL_Surface *surface = IMG_Load(path.c_str());
    SDL_Texture *temp = SDL_CreateTextureFromSurface(_render, surface);
    SDL_Rect rect {};

    SDL_QueryTexture(temp, NULL, NULL, &rect.w, &rect.h);
    rect.x = 0;
    rect.y = 0;
    SDL_RenderCopy(_render, temp, NULL, &rect);
    SDL_DestroyTexture(temp);
    SDL_FreeSurface(surface);
}

void Arcade::Sdl::clear()
{
    SDL_RenderClear(_render);
}

void Arcade::Sdl::drawText(Arcade::Text *text)
{
    SDL_Texture *texture {};
    SDL_Surface *temp = TTF_RenderText_Solid(_font, text->getText().c_str(),
    Arcade::sdlColor[text->getColor()]);
    SDL_Rect rect = {};
    int h, w;

    texture = SDL_CreateTextureFromSurface(_render, temp);
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    rect.w = w;
    rect.h = h;
    rect.x = text->getPos().first;
    rect.y = text->getPos().second;
    SDL_RenderCopy(_render, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(temp);
}

void Arcade::Sdl::draw(std::shared_ptr<Arcade::IObject> obj)
{
    if (dynamic_cast<Arcade::Object*>(obj.get()) != nullptr)
        drawObject(dynamic_cast<Arcade::Object *>(obj.get()));
    else if (dynamic_cast<Arcade::Text*>(obj.get()) != nullptr)
        drawText(dynamic_cast<Arcade::Text*>(obj.get()));
}

Arcade::Input Arcade::Sdl::getEvent()
{
    SDL_Event event{};

    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT)
            return (Input::ESCAPE);
        if (event.type == SDL_KEYDOWN) {
            if (Key_list.find(event.key.keysym.sym) != Key_list.end())
                return Key_list[event.key.keysym.sym];
        }
    }
    return (Arcade::Input::NOTHING);
}

void Arcade::Sdl::update()
{
    SDL_RenderPresent(_render);
}