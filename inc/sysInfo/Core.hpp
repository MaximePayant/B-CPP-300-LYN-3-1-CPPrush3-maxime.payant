/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Core.hpp
*/

#ifndef __CORE_H__
#define __CORE_H__

#include <iostream>
#include <thread>

namespace sysI
{

    class Core
    {

        private:
            unsigned _procCount;

        public:
            Core() {};

            void checkCore();
            unsigned getProcCount() const;

    };

}

inline std::ostream& operator<<(std::ostream& os, const sysI::Core& core)
{
    os <<  "Number of Processor: " << core.getProcCount() << std::endl;
    return (os);
}

#endif // __CORE_H__