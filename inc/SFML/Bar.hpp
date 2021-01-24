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
        public:
            typedef enum {RAM, SWAP, CORE} BarType;
            const sf::IntRect barPrefab[3] = {{0, 761, 530, 21},
                                              {0, 783, 167, 21},
                                              {0, 805, 206, 21}};

        private:
            sf::Vector2f _pos;
            sf::Sprite _spr;
            BarType _type;

        public:
            Bar() {};
            Bar(const sf::Vector2f& pos, BarType type);
            ~Bar();

            const sf::Sprite& get() const { return (_spr); };
            void setPercent(double percent);

    };

}

#endif // __BAR_H__