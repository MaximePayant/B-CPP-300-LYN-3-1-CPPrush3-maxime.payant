/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** sfml.cpp
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "sfml.hpp"

int MyGKrellmGraphics()
{
    sf::RenderWindow rwindow({910, 710}, "MyGKrellM");
    sf::Event event;

    sf::Texture interface;
    interface.loadFromFile("rsc/Interface rush3.png");

    sf::Sprite background(interface, {0, 0, 910, 710});

    while (rwindow.isOpen()) {
        while (rwindow.pollEvent(event))
            if (event.type == sf::Event::Closed)
                rwindow.close();
        rwindow.clear(sf::Color::Cyan);
        rwindow.draw(background);
        rwindow.display();
    }

    return (0);
}