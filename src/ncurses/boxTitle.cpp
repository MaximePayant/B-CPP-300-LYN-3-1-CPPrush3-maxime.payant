/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** boxTitle
*/
#include "ncurses.hpp"

void boxTitle(WINDOW *win, std::string title)
{
    mvwprintw(win, 0, 2, title.c_str());
}