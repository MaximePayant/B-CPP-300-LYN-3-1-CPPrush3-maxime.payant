/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** HostName
*/

#include "HostName.hpp"
#include <fstream>
#include <string>

sysI::HostName::HostName()
{
    std:: ifstream in("/proc/sys/kernel/hostname");

    getline(in, _hostName);
}

sysI::HostName::~HostName()
{
}
