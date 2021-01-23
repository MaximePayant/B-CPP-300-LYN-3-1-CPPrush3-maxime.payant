/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** dataBar
*/
#include "ncurses.hpp"

void dataBar(int ttyWidth, int top, int left, std::string title, double val)
{
    int height = 4;
    int width = ttyWidth / 3 - 2;
    int valScreen = (val / 100) * (ttyWidth / 3 - 4);
    std::string s;
    std::stringstream sstream;
    sstream.setf(std::ios::fixed);
    sstream.precision(2);
    sstream << val;
    s = sstream.str();

    WINDOW *dataView = newwin(height, width, top, left + 1);
    refresh();

    box(dataView, 0, 0);
    mvwprintw(dataView, 0, 3, title.c_str());
    mvwprintw(dataView, 1, 2, "[");
    for (int i = 3; i < valScreen + 3 && i < ttyWidth / 3 - 4; i++)
        mvwprintw(dataView, 1, i, "#");
    mvwprintw(dataView, 1, (ttyWidth / 3 - 4), "]");
    mvwprintw(dataView, 2, 2, "Value: %s%%", s.c_str());

    wrefresh(dataView);
}