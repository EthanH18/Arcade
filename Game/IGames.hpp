/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
    #define IGAMES_HPP_

#include <exception>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <memory>

#include "../Lib/IObject.hpp"
#include "../IDisplayModule.hpp"

namespace Arcade {

class IGames : public IDisplayModule {
    public:
        virtual ~IGames() = default;
        virtual std::vector<std::shared_ptr<Arcade::IObject>> play(Arcade::Input Input) = 0;
        const  std::string &getName() override {
            return _name;
        }
        virtual bool endGame() = 0;
        virtual int getScore() = 0;
        protected:
            const std::string _name { "IGames" };
};

}

#endif /* !IGAMES_HPP_ */