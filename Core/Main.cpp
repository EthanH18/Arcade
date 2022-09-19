/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-ethan.hayot
** File description:
** Main
*/

#include <iostream>
#include <dlfcn.h>

#include "../LibraryLoader.hpp"
#include "Core.hpp"

void error_check(int ac, char **av)
{
    if (ac != 2)
        throw ErrorFile("ARCADE: Usage: ./arcade ./lib/lib_arcade_xxx.so");
}

int main(int ac, char **av)
{
    try {
        error_check(ac, av);
        std::string str = std::string(av[1]);
        Arcade::Core test(str);
    } catch (std::exception const &e) {
        std::cout << std::endl << "ok:\t" << e.what() << std::endl;
        return 84;
    }
    return 0;
}