/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-ethan.hayot
** File description:
** ILib
*/

#ifndef ILIB_HPP_
    #define ILIB_HPP_

#include <memory>
#include <map>

#include "../Lib/Text.hpp"
#include "../Lib/Object.hpp"
#include "../Lib/IObject.hpp"
#include "../IDisplayModule.hpp"
#include "../Core/Error.hpp"

namespace Arcade {

    class IGraphic : public IDisplayModule {
        public:
            virtual ~IGraphic() = default;
            virtual void draw(std::shared_ptr<Arcade::IObject> obj) = 0;
            virtual void clear() = 0;
            virtual void update() = 0;
            virtual Arcade::Input getEvent() = 0;
            virtual void createWindow() = 0;
            virtual void drawBackground(std::string) = 0;
            const  std::string &getName() override {
                return _name;
            }
        protected:
            const std::string _name { "IGraphic" };
    };
    
    class AGraphic : public IGraphic {
        public:
        virtual ~AGraphic() = default;
        virtual void drawObject(Arcade::Object *) = 0;
        virtual void drawText(Arcade::Text *) = 0;
    };

}

#endif /* !ILIB_HPP_ */
