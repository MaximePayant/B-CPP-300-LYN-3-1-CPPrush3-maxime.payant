/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** sfml.cpp
*/

#include "sfml.hpp"
#include "Body.hpp"

bool MyGKrellmGraphics(sysI::Body& body)
{
    (void)body;
    static sfI::System system;

    if (!system._rwindow.isOpen())
        return (false);
    while (system._rwindow.pollEvent(system._event)) {
        if (system._event.type == sf::Event::Closed) {
            system._rwindow.close();
            return (false);
        }
        //if (system._event.type == sf::Event::KeyPressed
        //&& system._event.key.code == sf::Keyboard::A) {
        //    body._Lib = sysI::Body::NCURSES;
        //    system._rwindow.close();
        //}
    }
    system._rwindow.clear(sf::Color::Cyan);
    system.draw();
    system._rwindow.display();
    return (true);
}