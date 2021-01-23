/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** ncurses.hpp
*/

#ifndef __NCURSES_H__
#define __NCURSES_H__
#include <ncurses.h>
#include <iostream>
#include <sstream>
#include <string>

int MyGKrellmTerminal();
void headInfo(int ttyWidth);
void memoryInfo(int ttyWidth);
void boxTitle(WINDOW *win, std::string title);
void cpuInfo(int ttyWidth);
void dataBar(int ttyWidth, int top, int left, std::string name, double val);


#endif // __NCURSES_H__