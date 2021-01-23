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
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

namespace sysI
{

    class Core
    {

        private:
            class CPU
            {
                private:
                    unsigned _lastTotalJiffies;
                    unsigned _lastWorkJiffies;
                    double _percent;

                public:
                    CPU();

                    void updateCPU(unsigned index, const std::string& cpuInfo);
                    double getPercent() { return (_percent); };
            };
            unsigned _coreCount;
            std::map<std::string, CPU> _core;

        public:
            Core();

            void checkCore();
            unsigned getCoreCount() const;

    };

}

inline std::ostream& operator<<(std::ostream& os, const sysI::Core& core)
{
    os <<  "Number of Processor: " << core.getCoreCount() << std::endl;
    return (os);
}

#endif // __CORE_H__