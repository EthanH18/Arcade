/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** IDisplayModule
*/


#ifndef IDISPLAYMODULE_HPP_
    #define IDISPLAYMODULE_HPP_

#include <iostream>

namespace Arcade {

    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;
            virtual const  std::string &getName() = 0;
    };

}

#endif /* !IDISPLAYMODULE_HPP_ */