/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** Nibbler
*/

#include "Nibbler.hpp"

static const char snake_map[] = "assets/nibbler/map.txt";
static const char snake_down[] = "assets/nibbler/head_nibbler_down.png";
static const char snake_up[] = "assets/nibbler/head_nibbler_up.png";
static const char snake_left[] = "assets/nibbler/head_nibbler_left.png";
static const char snake_right[] = "assets/nibbler/head_nibbler_right.png";
static const char snake_body[] = "assets/nibbler/nibbler_body.png";
static const char snake_food[] = "assets/nibbler/bonus.png";
static const char snake_food_bonus[] = "assets/nibbler/nibbler_bonus.png";
static const char wall[] = "assets/nibbler/delim.png";
static const char sol[] = "assets/nibbler/ground.png";

Arcade::Snake::Snake()
{
    init_map();
    bonus_init();
    bonus_gen();
    init_score();
}

void Arcade::Snake::init_score()
{
    _txt.emplace_back(std::make_shared<Arcade::Text>("SCORE", Arcade::Color::GREEN, 920.f, 250.f));
    _txt.emplace_back(std::make_shared<Arcade::Text>(std::to_string(_score), Arcade::Color::GREEN, 948.f, 300.f));
}

bool Arcade::Snake::check_food(std::pair<float, float> pos)
{
    int i = 0;
	if (pos.first == 0 && pos.second == 0)
		return false;
	while (i <= _sizenibbler - 1) {
		if (_nibbler[i]->getPos().first == pos.first
		    && _nibbler[i]->getPos().second == pos.second)
			return (false);
		i++;
	}
    for (auto tmp : _wall) {
        auto pos_wall = tmp->getPos();
        if (pos.first == pos_wall.first && pos.second == pos_wall.second)
            return false;
    }
	return (true);
}

void Arcade::Snake::bonus_init()
{
    _obj.emplace_back(std::make_shared<Arcade::Object>(snake_food, 'F', Arcade::Color::RED, 0, 0));
}

void Arcade::Snake::bonus_gen()
{
    auto pos = std::make_pair(0.0, 0.0);

    _time++;
    srand(time(NULL));
    while (check_food(pos) != true) {
        pos.first = (float)(rand() % (map_size.first - 2) + 1);
        pos.second = (float)(rand() % (map_size.second - 2) + 1);
    }
    _obj.back()->setPos(pos.first, pos.second);
    if (_time % 5 == 0) {
        _obj.back()->setPath(snake_food_bonus);
        _inc = 3;
    }
    else if (_obj.back()->getPath().compare(snake_food) != 0) {
        _obj.back()->setPath(snake_food);
        _inc = 1;
    }
}

void Arcade::Snake::init_map()
{
    std::ifstream file(snake_map);
    std::string tmp;
    int y = 0;
    int i = 0;

    if (!file.is_open())
        throw std::exception();
    while (std::getline(file, tmp)) {
        if (y == 0)
            map_size.first = tmp.size();
        for (int x = 0; tmp[x] != '\0'; x++) {
            if (tmp[x] == '#')
                _wall.emplace_back(std::make_shared<Arcade::Object>(wall, tmp[x], Arcade::Color::CYAN, (float)x, (float)y));
            else if (tmp[x] == '0') {
                if (_nibbler.empty() == true)
                    _nibbler.emplace_back(std::make_shared<Arcade::Object>(snake_right, '>', Arcade::Color::GREEN, (float)x, (float)y));
                else
                    _nibbler.emplace_back(std::make_shared<Arcade::Object>(snake_body, tmp[x], Arcade::Color::GREEN, (float)x, (float)y));
                _obj.emplace_back(std::make_shared<Arcade::Object>(sol, ' ', Arcade::Color::GREEN, (float)x, (float)y));
            }
            if (tmp[x] == ' ')
                _obj.emplace_back(std::make_shared<Arcade::Object>(sol, tmp[x], Arcade::Color::BLACK, (float)x, (float)y));
        }
        y++;
    }
    map_size.second = y;
}

bool Arcade::Snake::is_bonus(float x, float y)
{
    if (_obj.back()->getPos().first == x &&
    _obj.back()->getPos().second == y) {
        _score += _inc;
        _sizenibbler++;
        bonus_gen();
        return true;
    }
    return false;
}

void Arcade::Snake::move(Arcade::Input dir)
{    
    if (dir == Input::PAUSE) {
        if  (!_ispause)
            _ispause = true;
        else
            _ispause = false;
    }
    if ((dir == Input::DOWN && _direction != Input::UP) ||
    (dir == Input::LEFT && _direction != Input::RIGHT) ||
    (dir == Input::RIGHT && _direction != Input::LEFT) ||
    (dir == Input::UP && _direction != Input::DOWN))
        _direction = dir;
}

std::vector<std::shared_ptr<Arcade::IObject>> Arcade::Snake::allObj()
{
    std::vector<std::shared_ptr<Arcade::IObject>> obj;
    for (auto &elem : _obj)
        obj.emplace_back(elem);
    for (auto &elem : _wall)
        obj.emplace_back(elem);
    for (auto &elem : _nibbler)
        obj.emplace_back(elem);
    for (auto &tmp : _txt)
        obj.emplace_back(tmp);
    return (obj);
}

std::vector<std::shared_ptr<Arcade::IObject>> Arcade::Snake::play(Arcade::Input Input)
{
    move(Input);
    if (!_ispause)
        movements();
    _txt.back()->setText(std::to_string(_score));
    return (allObj());
}

void Arcade::Snake::movements()
{
    auto it = _nibbler.begin();
    float x = 0;
    float y = 0;

    if (_direction == Input::LEFT) {
        x = it->get()->getPos().first - 1;
        y = it->get()->getPos().second;
        _nibbler.front()->setPath(snake_body);
        _nibbler.front()->setSymbol('0');
        _nibbler.insert(it, std::make_shared<Arcade::Object>(snake_left, '<', Arcade::Color::GREEN, (float)x, (float)y));
        if (!is_bonus(x, y))
            _nibbler.pop_back();
    }
    else if (_direction == Input::RIGHT) {
        x = it->get()->getPos().first + 1;
        y = it->get()->getPos().second;
        _nibbler.front()->setPath(snake_body);
        _nibbler.front()->setSymbol('0');
        _nibbler.insert(it, std::make_shared<Arcade::Object>(snake_right, '>', Arcade::Color::GREEN, (float)x, (float)y));
        if (!is_bonus(x, y))
            _nibbler.pop_back();
    }
    else if (_direction == Input::UP) {
        x = it->get()->getPos().first;
        y = it->get()->getPos().second - 1;
        _nibbler.front()->setPath(snake_body);
        _nibbler.front()->setSymbol('0');
        _nibbler.insert(it, std::make_shared<Arcade::Object>(snake_up, 'A', Arcade::Color::GREEN, (float)x, (float)y));
        if (!is_bonus(x, y))
            _nibbler.pop_back();
    }
    else if (_direction == Input::DOWN) {
        x = it->get()->getPos().first;
        y = it->get()->getPos().second + 1;
        _nibbler.front()->setPath(snake_body);
        _nibbler.front()->setSymbol('0');
        _nibbler.insert(it, std::make_shared<Arcade::Object>(snake_down, 'V', Arcade::Color::GREEN, (float)x, (float)y));
        if (!is_bonus(x, y))
            _nibbler.pop_back();
    }
}

bool Arcade::Snake::endGame()
{
    auto pos_snake = _nibbler.front()->getPos();
    for (auto tmp : _wall) {
        auto pos = tmp->getPos();
        if (pos.first == pos_snake.first && pos.second == pos_snake.second)
            return true;
    }
    for (int i = 1; i < _sizenibbler; i++) {
        if (pos_snake.first == _nibbler[i].get()->getPos().first
        && pos_snake.second == _nibbler[i].get()->getPos().second)
            return true;
    }
    return false;
}