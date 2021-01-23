/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** ncurses.cpp
*/

#include "ncurses.hpp"
#include "Body.hpp"
#include <sys/ioctl.h>
#include <unistd.h>
#include <ncurses.h>

bool MyGKrellmTerminal(sysI::Body& body)
{
    (void)body;
    int ttyW;
    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    ttyW = w.ws_col;
    initscr();
    headInfo(ttyW);
    memoryInfo(ttyW);
    cpuInfo(ttyW);
    dataBar(ttyW, 9, 1, "Name", 60);

    getch();
    endwin();
    return (true);
}