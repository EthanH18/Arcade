/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** ncurse.cpp
*/

#include "Ncurses.hpp"

void Arcade::Ncurses::createWindow()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(FALSE);
    start_color();
    init_pair(0, BLACK, 0);
    init_pair(1, RED, 0);
    init_pair(2, GREEN, 0);
    init_pair(3, YELLOW, 0);
    init_pair(4, BLUE, 0);
    init_pair(5, MAGENTA, 0);
    init_pair(6, CYAN, 0);
    init_pair(7, WHITE, 0);
}

Arcade::Ncurses::Ncurses() {}

Arcade::Ncurses::~Ncurses()
{
    endwin();
}

void Arcade::Ncurses::drawObject(Arcade::Object *obj)
{
    char tmp[2];

    tmp[0] = static_cast<char>(obj->getSymbol());
    tmp[1] = '\0';
    attron(COLOR_PAIR(obj->getColor()) | A_BOLD);
    mvwprintw(stdscr, round(obj->getPos().second), round(obj->getPos().first) * 2, tmp);
    attroff(COLOR_PAIR(obj->getColor()) | A_BOLD);
}

void Arcade::Ncurses::drawBackground(std::string)
{

}

void Arcade::Ncurses::clear()
{
    wclear(stdscr);
}

void Arcade::Ncurses::drawText(Arcade::Text *text)
{
    attron(COLOR_PAIR(text->getColor()) | A_BOLD);
    mvwprintw(stdscr, round(text->getPos().second) / 25, round(text->getPos().first) / 10, text->getText().c_str());
    attroff(COLOR_PAIR(text->getColor()) | A_BOLD);
}

void Arcade::Ncurses::draw(std::shared_ptr<Arcade::IObject> obj)
{
    if (dynamic_cast<Arcade::Object*>(obj.get()) != nullptr)
        drawObject(dynamic_cast<Arcade::Object *>(obj.get()));
    else if (dynamic_cast<Arcade::Text*>(obj.get()) != nullptr)
        drawText(dynamic_cast<Arcade::Text*>(obj.get()));
}

Arcade::Input Arcade::Ncurses::getEvent()
{
    int event = getch();
    Arcade::Input Input = NOTHING;

    while (event != ERR) {
        if (Key_list.find(event) != Key_list.end())
            Input = Key_list[event];
        if (event == 10)
            break;
        event = getch();
    }
    return Input;
}

void Arcade::Ncurses::update()
{
    wrefresh(stdscr);
    usleep(90000);
}