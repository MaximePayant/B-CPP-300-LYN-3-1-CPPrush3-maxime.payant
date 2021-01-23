/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Core.hpp
*/

#include "Core.hpp"

void sysI::Core::checkCore()
{
    _procCount = std::thread::hardware_concurrency();
}

unsigned sysI::Core::getProcCount() const
{
    return (_procCount);
}