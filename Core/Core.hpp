/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-ethan.hayot
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

#include <vector>

#include "../Game/IGames.hpp"
#include "../Lib/ILib.hpp"
#include "../Lib/Object.hpp"
#include "../Lib/Text.hpp"
#include "../Lib/IObject.hpp"
#include "../IDisplayModule.hpp"
#include "../LibraryLoader.hpp"
#include "../Ressource/Menu.hpp"
#include "../Ressource/Score.hpp"
#include "../Ressource/Sprite.hpp"
#include "Error.hpp"

namespace Arcade 
{
    class Core {
        public:
            Core(std::string &pathname);
            ~Core() = default;
            void exit();
            void next_game();
            void display_lib();
            void init_menu();
            void display_prev();
            void menu_draw(std::string);
            void core_loop();
            void load_file();
            void move_menu(Arcade::Input event);
            void endGame();
            void change_lib(Arcade::Input &input);
            void prev_game();
            void display_next();
            void best_score();
            void setScore();
        protected:
        private:
            std::size_t _grphit{0};
            std::vector<std::string> _gamelibs;
            DLLoader<Arcade::IGames> _game;
            DLLoader<Arcade::IDisplayModule> _liball;
            Menu _menu;
            std::size_t _gmsit{0};
            std::string _path;
            std::vector<std::string> _grphlibs;
            DLLoader<Arcade::IGraphic> _display;
            std::string _name;
            std::shared_ptr<Text>_best_score {
                std::make_shared<Text>("NOT AVAILABLE", Arcade::Color::GREEN, 1600.f, 100.f)};
            bool _is_menu{false};
            bool _pause{false};
            Score _score;
    };
}

#endif /* !CORE_HPP_ */
