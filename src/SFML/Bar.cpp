/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Bar.cpp
*/

#include "sfml.hpp"

sfI::Bar::Bar(const sf::Vector2f& pos, BarType type) :
_pos(pos),
_spr(sfI::System::interfaceTxt),
_type(type)
{
    _spr.setTextureRect(barPrefab[type]);
    _spr.setPosition(pos);
}

sfI::Bar::~Bar()
{}

void sfI::Bar::setPercent(double percent)
{
    sf::IntRect rect = _spr.getTextureRect();
    rect.width = (sfI::Bar::barPrefab[_type].width* percent) / 100;
    _spr.setTextureRect(rect);
}