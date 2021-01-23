/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** ncurses.cpp
*/

#include "ncurses.hpp"
#include <sys/ioctl.h>
#include <unistd.h>
#include <ncurses.h>

int MyGKrellmTerminal()
{
    int ttyW;
    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    ttyW = w.ws_col;
    initscr();
    headInfo(ttyW);
    memoryInfo(ttyW);
    cpuInfo(ttyW);

    getch();
    endwin();
    return 0;
}