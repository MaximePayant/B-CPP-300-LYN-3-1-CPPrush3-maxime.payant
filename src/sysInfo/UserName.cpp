/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** UserName
*/
#include "UserName.hpp"
#include <unistd.h>
#include <pwd.h>

sysI::UserName::UserName()
{
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);

    if (pw) _userName = pw->pw_name;
}

sysI::UserName::~UserName()
{
}