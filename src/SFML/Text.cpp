/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Text.cpp
*/

#include "sfml.hpp"

sfI::Text::Text(const std::string& str, const sf::Vector2f& pos) :
_text(str, sfI::System::font, 28)
{
    _text.setPosition(pos);
    _text.setFillColor(sf::Color(175, 171, 163, 255));
}

sfI::Text::~Text()
{}