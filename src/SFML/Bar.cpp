/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Bar.cpp
*/

#include "sfml.hpp"

sfI::Bar::Bar(const sf::Vector2f& pos, BarType type) :
_pos(pos),
_spr(sfI::System::interfaceTxt)
{
    _spr.setTextureRect(barPrefab[type]);
    _spr.setPosition(pos);
}

sfI::Bar::~Bar()
{}