/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** System.hpp
*/

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "Body.hpp"
#include "sfml.hpp"

namespace sfI
{

    class System
    {
        private:
            class Time
            {
                private:
                    static sf::Clock _clock;

                public:
                    double _last;
                    double _now;
                    double _dif;

                    Time();
                    ~Time();

                    void update();
                    void reset();
            } _time;

            sf::Sprite _background;
            std::unordered_map<std::string, Text> _textMap;
            std::unordered_map<std::string, Bar> _barMap;
            std::unordered_map<std::string, CoreModule> _coreMap;

            void updateMemory(sysI::Memory& mod);
            void updateTimeAndDate(sysI::TimeAndDate& mod);
            void updateCore(sysI::Core& mod);

        public:
            static sf::Font font;
            static sf::Texture interfaceTxt;

            sf::RenderWindow _rwindow;
            sf::Event _event;

            System(sysI::Body& body);
            ~System();

            bool createText(const std::string&code, const std::string& str, const sf::Vector2f& pos, unsigned size);
            bool createCoreModule(const std::string&code, const sf::Vector2f pos);
            bool createBar(const std::string&code, const sf::Vector2f& pos, sfI::Bar::BarType type);

            bool draw();
            void update(sysI::Body& body);

    };

}

#endif // __SYSTEM_H__