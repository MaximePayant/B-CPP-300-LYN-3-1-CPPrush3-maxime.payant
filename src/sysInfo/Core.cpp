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
_percent(0),
_frequency(""),
_maxFrequency(""),
_procInTime(""),
_cputemp("")
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

std::string check_frequency(std::string frequency) {
    int i = 0;
    FILE *neo = new FILE;
    char buff[500] = { 0 };

    for(int r = 0; r < 100 ; r++)
        buff[r] = '\0';
    neo = popen("lscpu | grep 'CPU MHz'", "r");
    fread(buff, sizeof buff, 1, neo);
    frequency = buff;
    frequency.erase(0, 12);
    while (frequency[i] < '0' || frequency[i] > '9')
        i++;
    frequency.erase(0, i);
    i = 0;
    frequency.replace(frequency.length() - 1, 1, "\0");
    pclose(neo);
    return frequency;
}

std::string check_MaxFrequency(std::string maxFrequency) {
    int i = 0;
    FILE *neo = new FILE;
    char buff[500] = { 0 };

    for(int r = 0; r < 100 ; r++)
        buff[r] = '\0';
    neo = popen("lscpu | grep 'CPU max MHz'", "r");
    fread(buff, sizeof buff, 1, neo);
    maxFrequency = buff;
    maxFrequency.erase(0, 12);
    while (maxFrequency[i] < '0' || maxFrequency[i] > '9')
        i++;
    maxFrequency.erase(0, i);
    i = 0;
    maxFrequency.replace(maxFrequency.length() - 1, 1, "\0");
    pclose(neo);
    for(int r = 0; r < 100 ; r++)
        buff[r] = '\0';
    return maxFrequency;
}

std::string check_ProcInTime(std::string procInTime) {
    FILE *neo = new FILE;
    char buff[500] = { 0 };
    neo = popen("ps -eo pid | wc -l", "r");
    fread(buff, sizeof buff, 1, neo);
    procInTime = buff;
    procInTime.replace(procInTime.length() - 1, 1, "\0");
    pclose(neo);
    return procInTime;
}

std::string check_cpuTemp(std::string cputemp) {
    FILE *neo = new FILE;
    char buff[500] = { 0 };
    neo = popen("cat /sys/class/thermal/thermal_zone0/temp", "r");
    fread(buff, sizeof buff, 1, neo);
    std::string tempo = buff;
    cputemp = tempo.substr(0,2);
    pclose(neo);
    return cputemp;
}

void sysI::Core::CPU::updateCPU(unsigned index, const std::string& cpuInfo)
{
    unsigned totalJiffies = calcTotalJiffies(index, cpuInfo);
    unsigned workJiffies = calcWorkJiffies(index, cpuInfo);
    double work_over = workJiffies - _lastWorkJiffies;
    double total_over = totalJiffies - _lastTotalJiffies;

    _percent = (work_over / total_over) * 100;
    _frequency = check_frequency(_frequency);
    _maxFrequency = check_MaxFrequency(_maxFrequency);
    _lastTotalJiffies = totalJiffies;
    _lastWorkJiffies = workJiffies;
    _procInTime = check_ProcInTime(_procInTime);
    _cputemp = check_cpuTemp(_cputemp);
}

const std::string &sysI::Core::CPU::getFrequency() const {
    return _frequency;
}

const std::string &sysI::Core::CPU::getMaxFrequency() const {
    return _maxFrequency;
}

const std::string &sysI::Core::CPU::getProcInTime() const {
    return _procInTime;
}

const std::string &sysI::Core::CPU::getCputemp() const {
    return _cputemp;
}

std::string check_name(std::string name) {
    int i = 0;
    FILE *neo = new FILE;
    char buff[500] = { 0 };

    neo = popen("lscpu | grep 'Model name'", "r");
    fread(buff, sizeof buff, 1, neo);
    name.append(buff);
    name.erase(0, 12);
    while ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z'))
        i++;
    name.erase(0, i);
    i = 0;
    name.replace(name.length() - 1, 1, "\0");
    return name;
}


sysI::Core::Core()
{
    _coreCount = std::thread::hardware_concurrency();
    _name = check_name(_name);
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

const std::string &sysI::Core::getName() const {
    return _name;
}