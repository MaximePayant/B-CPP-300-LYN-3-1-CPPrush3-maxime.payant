/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** OsInfo
*/

#include "OsInfo.hpp"
#include <sys/utsname.h>

sysI::OsInfo::OsInfo()
{
    struct utsname name;

    uname(&name);
    _osName = name.sysname;
    _osVersion = name.version;
    _hardwareId = name.machine;
}

sysI::OsInfo::~OsInfo()
{
}
