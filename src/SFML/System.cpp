/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** System.cpp
*/

#include "sfml.hpp"

sf::Texture sfI::System::interfaceTxt;
sf::Font sfI::System::font;

sfI::System::System(sysI::Body& body) :
_time(),
_background(sfI::System::interfaceTxt, {0, 0, 910, 760}),
_textMap(),
_coreMap(),
_rwindow({910, 760}, "MyGKrellM"),
_event()
{
    font.loadFromFile("rsc/Robot.otf");
    interfaceTxt.loadFromFile("rsc/Interface rush3.png");
    sfI::CoreModule::coreModule.setTexture(sfI::System::interfaceTxt);
    sfI::CoreModule::coreModule.setTextureRect({0, 827, 290, 99});

    createText("ramText", "Memory:", {30, 187}, 28);
    createBar( "ram", {62, 224},  sfI::Bar::RAM);
    createText("swapText", "Swap:", {654, 193}, 22);
    createBar("swap", {681, 224}, sfI::Bar::SWAP);

    createText("host", body.getModuleHostName()._hostName, {22, 12}, 28);
    createText("user", body.getModuleUserName()._userName, {22, 40}, 28);
    createText("osName", body.getModuleOsInfo()._osName, {22, 68}, 28);
    createText("osVersion", "  -" + body.getModuleOsInfo()._osVersion, {22, 102}, 12);

    createText("date", body.getModuleTimeAndDate()._date, {620, 12}, 28);
    createText("time", body.getModuleTimeAndDate()._time, {620, 40}, 28);

    createText("proc", body.getModuleCore().getName(), {30, 300}, 24);
    createText("temp", body.getModuleCore().getCputemp() + " C", {700, 300}, 24);

    //std::string test = (body.getModuleNetwork().checkConnection() ? "Yes" : "No");
    //createText("connected", "Connected: " + test, {620, 68}, 28);
    //createText("bUp", "Up: " + (body.getModuleNetwork().getByteUp().empty() ? "???" : body.getModuleNetwork().getByteUp()), {650, 100}, 18);
    //createText("bDown", "Down: " + (body.getModuleNetwork().getByteDown().empty() ? "???" : body.getModuleNetwork().getByteDown()), {750, 100}, 18);

    for (unsigned ctr = 0; ctr < body.getModuleCore().getCoreCount(); ctr += 1) {
        std::string cpu = "cpu" + std::to_string(ctr);
        std::string cpuBar = "cpuBar" + std::to_string(ctr);
        std::string cpuText = "cpuText" + std::to_string(ctr);
        std::string cpuTextHz = "cpuTextHz" + std::to_string(ctr);
        createCoreModule(cpu, sfI::CoreModule::posList[ctr]);
        createBar(cpuBar, sfI::CoreModule::barPosList[ctr], sfI::Bar::CORE);
        createText(cpuText, "Cpu" + std::to_string(ctr), sfI::CoreModule::textPosList[ctr], 20);
        createText(cpuTextHz, "MHz", sfI::CoreModule::textPosList[ctr] + sf::Vector2f(172, 10), 14);
    }


}

sfI::System::~System()
{}

bool sfI::System::createText(const std::string&code, const std::string& str, const sf::Vector2f& pos, unsigned size)
{
    _textMap.try_emplace(code, str, pos, size);
    return (true);
}

bool sfI::System::createCoreModule(const std::string&code, const sf::Vector2f pos)
{
    _coreMap.try_emplace(code, pos);
    return (true);
}

bool sfI::System::createBar(const std::string&code, const sf::Vector2f& pos, sfI::Bar::BarType type)
{
    _barMap.try_emplace(code, pos, type);
    return (true);
}

bool sfI::System::draw()
{
    _rwindow.draw(_background);
    for (auto &[_, module] : _coreMap) {
        sfI::CoreModule::coreModule.setPosition(module.get());
        _rwindow.draw(sfI::CoreModule::coreModule);
    }
    for (auto &[_, module] : _textMap)
        _rwindow.draw(module.get());
    for (auto &[_, module] : _barMap)
        _rwindow.draw(module.get());
    return (true);
}