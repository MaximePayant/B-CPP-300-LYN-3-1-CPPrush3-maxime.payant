/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** OsInfo
*/

#ifndef OSINFO_HPP_
#define OSINFO_HPP_

#include <iostream>

namespace sysI {
    class OsInfo {
        public:
            OsInfo();
            ~OsInfo();

            std :: string _osName;
            std :: string _osVersion;
            std :: string _hardwareId;
    };
}

#endif /* !OSINFO_HPP_ */
