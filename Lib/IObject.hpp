/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** IObject.hpp
*/

#ifndef IOBJECT_HPP_
    #define IOBJECT_HPP_

#include <vector>
#include <utility>
#include <string>

namespace Arcade {

class IObject {
    public:
        virtual ~IObject() = default;
};

enum Color {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

enum Input {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ENTER,
        ESCAPE,
        MENU,
        RESTART,
        PREV_GAME,
        NEXT_GAME,
        PREV_LIB,
        NEXT_LIB,
        PAUSE,
        NOTHING
    };
}

#endif /* !IOBJECT_HPP_ */
