/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** TimeAndDate
*/

#ifndef TIMEANDDATE_HPP_
#define TIMEANDDATE_HPP_
#include <iostream>

namespace sysI {
    class TimeAndDate {
        public:
            TimeAndDate();
            ~TimeAndDate();
            void update();

            std::string _time;
            std::string _date;
    };
}

#endif /* !TIMEANDDATE_HPP_ */
