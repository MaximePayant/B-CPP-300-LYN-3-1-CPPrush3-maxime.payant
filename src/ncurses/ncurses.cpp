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
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    initscr();
    printw("%d\n", w.ws_row);
    printw("%d col\n", w.ws_col);
    headInfo();

    refresh();
    getch();
    endwin();
    return 0;
}