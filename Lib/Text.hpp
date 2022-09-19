/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** text.hpp
*/

#ifndef TEXT_HPP_
    #define TEXT_HPP_

#include "IObject.hpp"

namespace Arcade {

    class Text : public IObject {
        public:
            Text(std::string text, Arcade::Color color, float x, float y):
                _txt(text), _color(color), _txtposition(std::make_pair(x, y)) {};
            ~Text() override = default;

            std::string getText() const {
                return _txt;
            };
            Arcade::Color getColor() const {
                return _color;
            };
            std::pair<float, float> getPos() const {
                return _txtposition;
            };

            void setText(std::string text) {
                _txt = std::move(text);
            };
            void setColor(Arcade::Color color) {
                _color = color;
            };
            void setPos(float x, float y) {
                _txtposition.first = x;
                _txtposition.second = y;
            };

        protected:
        private:
        std::string _txt;
        Arcade::Color _color;
        std::pair<float, float> _txtposition;
    };
}

#endif /* !TEXT_HPP_ */