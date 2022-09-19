/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Object.hpp
*/

#ifndef OBJECT_HPP_
    #define OBJECT_HPP_

#include "IObject.hpp"

namespace Arcade {

    class Object : public IObject {
        public:
            Object(std::string path, unsigned char symbol, Arcade::Color color,
            float x, float y) : _path(path), _symbol(symbol), _color(color),
            _objPos(std::make_pair(x, y)) {}
            ~Object() override = default;

            std::string getPath() const {
                return _path;
            }
            unsigned char getSymbol() const {
                return _symbol;
            }
            Arcade::Color getColor() const {
                return _color;
            }
            std::pair<float, float> getPos() const {
                return (_objPos);
            }

            void setPath(std::string path) {
                _path = std::move(path);
            }
            void setSymbol(unsigned char symbol) {
                _symbol = symbol;
            }
            void setColor(Arcade::Color color) {
                _color = color;
            }
            void setPos(float x, float y) {
                _objPos.first = x;
                _objPos.second = y;
            }

        protected:
        private:
        std::pair<float, float> _objPos;
        std::string _path;
        Arcade::Color _color;
        unsigned char _symbol;
    };
}

#endif /* !OBJECT_HPP_ */
