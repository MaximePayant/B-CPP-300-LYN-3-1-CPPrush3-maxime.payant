/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** System.cpp
*/

#include "sfml.hpp"

sf::Texture sfI::System::interfaceTxt;
sf::Font sfI::System::font;

sfI::System::System() :
_background(sfI::System::interfaceTxt, {0, 0, 910, 710}),
_textMap(),
_coreMap(),
_rwindow({910, 710}, "MyGKrellM"),
_event()
{
    font.loadFromFile("rsc/Robot.otf");
    interfaceTxt.loadFromFile("rsc/Interface rush3.png");
    sfI::CoreModule::coreModule.setTexture(sfI::System::interfaceTxt);
    sfI::CoreModule::coreModule.setTextureRect({0, 777, 290, 99});

    createBar( "ram", {62, 224},  sfI::Bar::RAM);
    createBar("swap", {681, 224}, sfI::Bar::SWAP);

    createCoreModule("cpu1", {10, 300});
    createBar("cpu1bar", {52, 346}, sfI::Bar::CORE);

    createText("ramText", "Memory:", {30, 187});
}

sfI::System::~System()
{}

bool sfI::System::createText(const std::string&code, const std::string& str, const sf::Vector2f& pos)
{
    _textMap.try_emplace(code, str, pos);
    return (true);
}

bool sfI::System::createCoreModule(const std::string&code, const sf::Vector2f& pos)
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