/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** sfml.cpp
*/

#include "Sfml.hpp"

void Arcade::Sfml::createWindow()
{
    _wndw.create(sf::VideoMode(1920, 1080), "Arcade {SFML}");
    _wndw.setFramerateLimit(60);
    _wndw.setKeyRepeatEnabled(true);
    if (!_font.loadFromFile("assets/font.ttf"))
        throw ErrorGame("Failed to load a font");
}

Arcade::Sfml::Sfml()
{
}

Arcade::Sfml::~Sfml()
{
    if (_wndw.isOpen())
        _wndw.close();
}

void Arcade::Sfml::drawObject(Arcade::Object *obj)
{
    if(!_txture.loadFromFile(obj->getPath().c_str()))
        throw ErrorGame("Failed to load a texture");
    sf::Sprite sprite(_txture);
    sprite.setPosition(600 + obj->getPos().first * 13, 365 + obj->getPos().second * 16);
    sprite.scale(0.55f, 0.55f);
    _wndw.draw(sprite);
}

void Arcade::Sfml::drawBackground(std::string path)
{
    if(!_txture.loadFromFile(path.c_str()))
        throw ErrorGame("Failed to load a texture");
    sf::Sprite sprite(_txture);
    sprite.setPosition(0, 0);
    _wndw.draw(sprite);
}

void Arcade::Sfml::clear()
{
    _wndw.clear(sf::Color::Black);
}

void Arcade::Sfml::drawText(Arcade::Text *text)
{
    sf::Text txt;

    txt.setFont(_font);
    txt.setString(text->getText());
    txt.setCharacterSize(25);
    txt.setPosition(text->getPos().first, text->getPos().second);
    txt.setFillColor(sfmlColor[text->getColor()]);
    _wndw.draw(txt);
}

void Arcade::Sfml::draw(std::shared_ptr<Arcade::IObject> obj)
{
    if (dynamic_cast<Arcade::Object*>(obj.get()) != nullptr)
        drawObject(dynamic_cast<Arcade::Object *>(obj.get()));
    else if (dynamic_cast<Arcade::Text*>(obj.get()) != nullptr)
        drawText(dynamic_cast<Arcade::Text*>(obj.get()));
}

Arcade::Input Arcade::Sfml::getEvent()
{
    sf::Event event;

    while (_wndw.pollEvent(event)) {
        if (event.type == sf::Event::Resized) {
            sf::FloatRect area(0, 0, event.size.width, event.size.height);
            _wndw.setView(sf::View(area));
            return (Arcade::Input::NOTHING);
        }
        if (event.type == sf::Event::Closed)
            return (Input::ESCAPE);
        if (event.type == sf::Event::KeyPressed) {
            if (Key_list.find(event.key.code) != Key_list.end())
                return Key_list[event.key.code];
        }
    }
    return (Arcade::Input::NOTHING);
}

void Arcade::Sfml::update()
{
    _wndw.display();
}