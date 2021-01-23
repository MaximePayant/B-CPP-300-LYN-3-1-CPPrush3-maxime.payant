/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Core.hpp
*/

#include "Core.hpp"

sysI::Core::CPU::CPU() :
_lastTotalJiffies(0),
_lastWorkJiffies(0),
_percent(0)
{}

static unsigned calcTotalJiffies(unsigned index, const std::string& cpuInfo)
{
    unsigned result = 0;
    std::size_t pos = std::string("cpu" + std::to_string(index)).size();

    for (int ctr = 0; ctr < 7; ctr += 1) {
        result += std::stoul(&(cpuInfo[pos]));
        pos = cpuInfo.find(" ", pos + 1);
    }
    return (result);
}

static unsigned calcWorkJiffies(unsigned index, const std::string& cpuInfo)
{
    unsigned result = 0;
    std::size_t pos = std::string("cpu" + std::to_string(index)).size();

    for (int ctr = 0; ctr < 3; ctr += 1) {
        result += std::stoul(&(cpuInfo[pos]));
        pos = cpuInfo.find(" ", pos + 1);
    }
    return (result);
}

void sysI::Core::CPU::updateCPU(unsigned index, const std::string& cpuInfo)
{
    unsigned totalJiffies = calcTotalJiffies(index, cpuInfo);
    unsigned workJiffies = calcWorkJiffies(index, cpuInfo);
    double work_over = workJiffies - _lastWorkJiffies;
    double total_over = totalJiffies - _lastTotalJiffies;

    _percent = (work_over / total_over) * 100;

    _lastTotalJiffies = totalJiffies;
    _lastWorkJiffies = workJiffies;
}

sysI::Core::Core()
{
    _coreCount = std::thread::hardware_concurrency();
    checkCore();
}

void sysI::Core::checkCore()
{
    std::ifstream file("/proc/stat");
    std::stringstream strStream;
    std::string str;

    strStream << file.rdbuf();
    str = strStream.str();

    for (unsigned ctr = 0; ctr < _coreCount; ctr += 1) {
        std::size_t pos = str.find("cpu" + std::to_string(ctr));
        std::size_t pos2 = str.find("\n", pos);
        _core["cpu" + std::to_string(ctr + 1)].updateCPU(ctr, str.substr(pos, pos2 - pos));
        std::cout << "cpu" << ctr + 1 << ": " << _core["cpu" + std::to_string(ctr + 1)].getPercent() << "%" << std::endl;
    }
}

unsigned sysI::Core::getCoreCount() const
{
    return (_coreCount);
}