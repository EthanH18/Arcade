/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Score
*/

#ifndef SCORE_HPP_
    #define SCORE_HPP_

#include <iostream>
#include <fstream>
#include <sstream>

namespace Arcade {

class Score {
    public:
        Score() = default;
        void loadScore() {
            std::ifstream file;
            std::string line;
            file.open(_path, std::ifstream::in);
            if (file.peek() == std::ifstream::traits_type::eof())
                _score.assign("NOT AVAILABLE");
            else {
                if (file.is_open() && std::getline(file, line))
                    _name = line;
                if (file.is_open() && std::getline(file, line))
                    _score = line;
            }
            file.close();
        }
        void writeScore(std::string name, std::string score) {
            std::fstream file;
            std::string line;
            std::string tmp;

            if (_score.compare("NOT AVAILABLE") == 0 || std::stoi(_score) < std::stoi(score)) {
                file.open(_path,  std::ios::trunc | std::ios::in | std::ios::out);
                file << name << "\n" << score << std::endl;
                _score = score;
                _name = name;
            }
            file.close();
        };
        void setPath(const std::string &path) {
            _path = path;
        }
        std::string getName() {
            return _name;
        }
        std::string getScore() {
            return _score;
        }

        ~Score() = default;

    protected:
    private:
        std::string _score {"NOT AVAILABLE"};
        std::string _name {};
        std::string _path;
};

}
#endif /* !SCORE_HPP_ */
