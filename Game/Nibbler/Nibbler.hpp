/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
    #define NIBBLER_HPP_

#include <unistd.h>

#include "../../Lib/Text.hpp"
#include "../../Lib/Object.hpp"
#include "../../Lib/IObject.hpp"
#include "../IGames.hpp"

namespace Arcade {

    class Snake : public IGames {
        public:
            Snake();
            ~Snake() = default;
            void init_map();
            void bonus_init();
            void init_score();
            void bonus_gen();
            bool check_food(std::pair<float, float> pos);
            void move(Arcade::Input);
            void movements();
            bool is_bonus(float x, float y);
            int getScore() override {
                return _score;
            }
            std::vector<std::shared_ptr<Arcade::IObject>> play(Arcade::Input Input) override;
            std::vector<std::shared_ptr<Arcade::IObject>> allObj();
            bool endGame() override;
        protected:
        private:
            bool _ispause{false};
            bool _game_over;
            int _time{0};
            int _score{0};
            int _inc{1};
            int _direction{-1};

            std::vector<std::shared_ptr<Arcade::Text>> _txt;
            std::vector<std::shared_ptr<Arcade::Object>> _nibbler;
            std::vector<std::shared_ptr<Arcade::Object>> _food;
            std::vector<std::shared_ptr<Arcade::Object>> _obj;
            std::vector<std::shared_ptr<Arcade::Object>> _wall;
            std::size_t _sizenibbler{2};
            std::pair<std::size_t, std::size_t> map_size;
    };
    
    extern "C" Snake *entryPoint() {
        return new Snake;
    };

}

#endif /* !NIBBLER_HPP_ */
