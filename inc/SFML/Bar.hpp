/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Bar.hpp
*/

#ifndef __BAR_H__
#define __BAR_H__

#include <SFML/Graphics.hpp>

namespace sfI
{

    class Bar
    {

        private:
            sf::Vector2f _pos;
            sf::Sprite _spr;

        public:
            typedef enum {RAM, SWAP, CORE} BarType;
            const sf::IntRect barPrefab[3] = {{0, 711, 530, 21},
                                              {0, 733, 167, 21},
                                              {0, 877, 206, 21}};

            Bar(const sf::Vector2f& pos, BarType type);
            ~Bar();

            const sf::Sprite& get() const { return (_spr); }

    };

}

#endif // __BAR_H__