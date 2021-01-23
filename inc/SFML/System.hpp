/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** System.hpp
*/

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "sfml.hpp"

namespace sfI
{

    class System
    {
        private:
            sf::Sprite _background;
            std::unordered_map<std::string, Text> _textMap;
            std::unordered_map<std::string, Bar> _barMap;
            std::unordered_map<std::string, CoreModule> _coreMap;

        public:
            static sf::Font font;
            static sf::Texture interfaceTxt;

            sf::RenderWindow _rwindow;
            sf::Event _event;

            System();
            ~System();

            bool createText(const std::string&code, const std::string& str, const sf::Vector2f& pos);
            bool createCoreModule(const std::string&code, const sf::Vector2f& pos);
            bool createBar(const std::string&code, const sf::Vector2f& pos, sfI::Bar::BarType type);

            bool draw();

    };

}

#endif // __SYSTEM_H__