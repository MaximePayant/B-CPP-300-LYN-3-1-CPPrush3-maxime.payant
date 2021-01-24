/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Time.cpp
*/

#include "sfml.hpp"

sf::Clock sfI::System::Time::_clock = sf::Clock();

sfI::System::Time::Time() :
_last(0),
_now(0),
_dif(0)
{}

sfI::System::Time::~Time()
{}

void sfI::System::Time::update()
{
    _now = _clock.getElapsedTime().asMicroseconds() / 1000000;
    _dif = _now - _last;
}

void sfI::System::Time::reset()
{
    _last = _now;
}