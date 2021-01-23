/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** memoryInfo
*/

#include "ncurses.hpp"

void memoryInfo(int ttyWidth)
{
    int height = 4;
    int width = ttyWidth / 3;
    int top = 5;
    int left = 1;

    WINDOW *memory= newwin(height, width, top, left);
    WINDOW *swap= newwin(height, width / 2, top, left + width);
    refresh();

    box(memory, 0, 0);
    box(swap, 0, 0);
    boxTitle(memory, "MEMORY");
    boxTitle(swap, "SWAP");
    wrefresh(memory);
    wrefresh(swap);
}