/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** CoreModule.cpp
*/

#include "CoreModule.hpp"

sf::Sprite sfI::CoreModule::coreModule;

sfI::CoreModule::CoreModule(const sf::Vector2f& pos) :
_pos(pos)
{}

sfI::CoreModule::~CoreModule()
{}