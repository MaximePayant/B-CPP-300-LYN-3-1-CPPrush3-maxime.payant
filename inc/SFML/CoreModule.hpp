/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** CoreModule.hpp
*/

#ifndef __COREMODULE_H__
#define __COREMODULE_H__

#include <SFML/Graphics.hpp>

namespace sfI
{

    class CoreModule
    {

        private:
            sf::Vector2f _pos;

        public:
            static sf::Sprite coreModule;

            CoreModule(const sf::Vector2f& pos);
            ~CoreModule();

            const sf::Vector2f& get() const { return (_pos); }

    };

}

#endif // __COREMODULE_H__