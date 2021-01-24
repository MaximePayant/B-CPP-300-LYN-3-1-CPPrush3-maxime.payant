/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Text.cpp
*/

#include "sfml.hpp"

sfI::Text::Text(const std::string& str, const sf::Vector2f& pos, unsigned size) :
_text(str, sfI::System::font, size)
{
    _text.setPosition(pos);
    _text.setFillColor(sf::Color(175, 171, 163, 255));
}

sfI::Text::~Text()
{}

void sfI::Text::setString(const std::string& str)
{
    _text.setString(str);
}