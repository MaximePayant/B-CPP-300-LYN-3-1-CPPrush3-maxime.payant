/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** Text.hpp
*/

#ifndef __TEXT_H__
#define __TEXT_H__

#include <SFML/Graphics.hpp>

namespace sfI
{

    class Text
    {

        private:
            sf::Text _text;

        public:
            Text() {};
            Text(const std::string& str, const sf::Vector2f& pos, unsigned size);
            ~Text();

            const sf::Text& get() const { return (_text); };
            void setString(const std::string& str);

    };

}
#endif // __TEXT_H__