/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** cpuInfo
*/
#include "ncurses.hpp"

void cpuInfo(int ttyWidth)
{
    int height = 10;
    int width = ttyWidth / 2;
    int top = 8;
    int left = 1;

    WINDOW *cpu= newwin(height, width, top, left);
    refresh();

    box(cpu, 0, 0);
    boxTitle(cpu, "MAIN DATA");
    wrefresh(cpu);
}