/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** main.cpp
*/

#include "sysInfo.hpp"
#include "ncurses.hpp"
#include <unistd.h>

int main()
{
    int i = MyGKrellmTerminal();

    // sysI::Memory mem;
    // sysI::UserName name;
    // sysI::OsInfo info;
    // sysI::HostName host;
    // sysI::TimeAndDate time;
    // sysI::Core core;

    // std::cout << "userName: " << name._userName << std ::endl;
    // std::cout << "OsName: " << info._osName << std :: endl;
    // std::cout << "OsVersion: " << info._osVersion << std :: endl;
    // std::cout << "HardWareId: " << info._hardwareId << std :: endl;
    // std::cout << "HostName: " << host._hostName << std :: endl;
    // std::cout << "Date: " << time._date << std :: endl;
    // std::cout << "Time: " << time._time << std :: endl;

    // mem.checkMemoryInfo();
    // sysI::Memory::memType = sysI::Memory::GB;
    // std::cout.precision(10);
    // std::cout << mem << std::endl;
    // usleep(2000000);
    // core.checkCore();
    // std::cout << core << std::endl;
    return (i);
}