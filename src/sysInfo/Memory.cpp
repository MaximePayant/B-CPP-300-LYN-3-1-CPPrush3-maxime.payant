/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Memory.cpp
*/

#include "Memory.hpp"

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

sysI::Memory::MemType sysI::Memory::memType = sysI::Memory::GB;

static double getValue(const std::string& str, const std::string& to_find)
{
    std::size_t pos = str.rfind(to_find) + to_find.size();
    return (std::stold(&(str.c_str()[pos])));
}

void sysI::Memory::checkMemoryInfo()
{
    std::ifstream file("/proc/meminfo");
    std::stringstream strStream;
    std::string str;

    strStream << file.rdbuf();
    str = strStream.str();

    _total = getValue(str, "MemTotal:");
    _slab = getValue(str, "Slab:");
    _cached = getValue(str, "Cached:");
    _buffer = getValue(str, "Buffers:");
    _free = getValue(str, "MemFree:");
    _swapTotal = getValue(str, "SwapTotal:");
    _swapFree = getValue(str, "SwapFree:");
}

double sysI::Memory::getTotalMem() const
{
    double result = 0;

    switch (memType) {
        case KB:
            result = _total;
            break;
        case MB:
            result = _total / 1024;
            break;
        case GB:
            result = _total / (1024 * 1024);
            break;
    }
    return (result);
}

double sysI::Memory::getUsedMem() const
{
    double result = 0;

    switch (memType) {
        case KB:
            result = _total - (_slab + _cached + _buffer + _free);
            break;
        case MB:
            result = (_total - (_slab + _cached + _buffer + _free)) / 1024;
            break;
        case GB:
            result = (_total - (_slab + _cached + _buffer + _free)) / (1024 * 1024);
            break;
    }
    return (result);
}

double sysI::Memory::getTotalSwap() const
{
    double result = 0;

    switch (memType) {
        case KB:
            result = _swapTotal;
            break;
        case MB:
            result = _swapTotal / 1024;
            break;
        case GB:
            result = _swapTotal / (1024 * 1024);
            break;
    }
    return (result);
}

double sysI::Memory::getUsedSwap() const
{
    double result = 0;

    switch (memType) {
        case KB:
            result = (_swapTotal - _swapFree);
            break;
        case MB:
            result = (_swapTotal - _swapFree) / 1024;
            break;
        case GB:
            result = (_swapTotal - _swapFree) / (1024 * 1024);
            break;
    }
    return (result);
}
