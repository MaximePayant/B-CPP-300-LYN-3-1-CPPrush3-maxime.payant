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
                    std::string _frequency;
                    std::string _maxFrequency;
                    std::string _procInTime;
                public:
                    CPU();

                    void updateCPU(unsigned index, const std::string& cpuInfo);
                    double getPercent() { return (_percent); };
                    const std::string &getFrequency() const;
                    const std::string &getMaxFrequency() const;
                    const std::string &getProcInTime() const;
            };
            std::string _cputemp;
            unsigned _coreCount;
            std::string _name;

        public:
            Core();
            std::map<std::string, CPU> _core;
            const std::string &getName() const;
            void checkCore();
            unsigned getCoreCount() const;
            const std::string &getCputemp() const;

    };

}

inline std::ostream& operator<<(std::ostream& os, const sysI::Core& core)
{
    os <<  "Number of Processor: " << core.getCoreCount() << std::endl;
    return (os);
}

#endif // __CORE_H__