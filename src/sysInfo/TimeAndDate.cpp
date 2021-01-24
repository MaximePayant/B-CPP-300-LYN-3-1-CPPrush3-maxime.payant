/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** TimeAndDate
*/

#include "TimeAndDate.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>

sysI::TimeAndDate::TimeAndDate() :
_time("NOW"),
_date("TODAY")
{
    update();
}

sysI::TimeAndDate::~TimeAndDate()
{}

void sysI::TimeAndDate::update()
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::ostringstream tmp;
    std::ostringstream tmp_time;

    tmp << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday;
    _date = tmp.str();
    tmp.clear();
    tmp_time << std::setw(2) << std::setfill('0') << now->tm_hour << ":"
             << std::setw(2) << std::setfill('0') << now->tm_min << ":"
             << std::setw(2) << std::setfill('0') << now->tm_sec;
    _time = tmp_time.str();
}