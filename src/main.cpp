/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** main.cpp
*/

#include "sysInfo.hpp"
#include "ncurses.hpp"
#include "sfml.hpp"
#include "Body.hpp"
#include <unistd.h>

int main()
{
    bool check = true;
    sysI::Body body(sysI::Body::SFML);

    while (check) {
        // update body
        check = body._prog[body._Lib](body);
    }
    return (0);
}