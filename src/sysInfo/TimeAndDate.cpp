/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** TimeAndDate
*/

#include "TimeAndDate.hpp"
#include <ctime>
#include <sstream>

sysI::TimeAndDate::TimeAndDate()
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::ostringstream tmp;
    std::ostringstream tmp_time;

    tmp << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday;
    _date = tmp.str();
    tmp.clear();
    tmp_time << now->tm_hour << ":" << now->tm_min;
    _time = tmp_time.str();
}

sysI::TimeAndDate::~TimeAndDate()
{
}