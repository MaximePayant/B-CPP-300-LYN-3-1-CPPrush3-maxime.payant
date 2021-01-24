/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** SystemUpdate.cpp
*/

#include "sfml.hpp"
#include "Body.hpp"
#include "sysInfo.hpp"

void sfI::System::updateMemory(sysI::Memory& mod)
{
    mod.checkMemoryInfo();
    std::stringstream memText;
    memText << "Memory: " << std::fixed << std::setprecision(2) << mod.getUsedMem() << "/" << mod.getTotalMem() << " GB";
    _textMap["ramText"].setString(memText.str());
    _barMap["ram"].setPercent((mod.getUsedMem() * 100) / mod.getTotalMem());

    std::stringstream memText2;
    memText2 << "Swap: " << std::fixed << std::setprecision(2) << mod.getUsedSwap() << "/" << mod.getTotalSwap() << " GB";
    _textMap["swapText"].setString(memText2.str());
    _barMap["swap"].setPercent((mod.getUsedSwap() * 100) / mod.getTotalSwap());
}

void sfI::System::updateTimeAndDate(sysI::TimeAndDate& mod)
{
    mod.update();
    _textMap["time"].setString(mod._time);
    _textMap["date"].setString(mod._date);
}

void sfI::System::updateCore(sysI::Core& mod)
{
    mod.checkCore();
    for (unsigned ctr = 0; ctr < mod.getCoreCount(); ctr += 1) {
        std::string cpu = "cpu" + std::to_string(ctr);
        std::string cpuBar = "cpuBar" + std::to_string(ctr);
        std::string cpuText = "cpuText" + std::to_string(ctr);
        std::string cpuTextHz = "cpuTextHz" + std::to_string(ctr);
        std::stringstream ss;
        ss << "Cpu" << ctr << ": " << std::setprecision(2) << std::fixed << mod._core[cpu].getPercent() << "%";
        std::stringstream ss2;
        double frequency = std::stold(mod._core[cpu].getFrequency()) / 1000;
        double maxFrequency = std::stold(mod._core[cpu].getMaxFrequency()) / 1000;
        ss2 << std::setprecision(2) << std::fixed << frequency << "/"
            << std::setprecision(2) << std::fixed << maxFrequency << "MHz";
        _textMap[cpuText].setString(ss.str());
        _textMap[cpuTextHz].setString(ss2.str());
        _barMap[cpuBar].setPercent(mod._core[cpu].getPercent());
    }
    _textMap["temp"].setString(mod.getCputemp() + " C");
}

void sfI::System::update(sysI::Body& body)
{
    static bool firstLoop = true;

    _time.update();
    if (_time._dif > 1 || firstLoop) {
        updateMemory(body.getModuleMemory());
        updateCore(body.getModuleCore());
        _time.reset();
    }
    updateTimeAndDate(body.getModuleTimeAndDate());
    firstLoop = false;
}