/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** headInfo
*/
#include "ncurses.hpp"

void headInfo(int ttyWidth)
{
    int height = 5;
    int width = ttyWidth - 1;
    int top = 1;
    int left = 1;

    WINDOW *head = newwin(height, width, top, left);
    refresh();

    box(head, 0, 0);
    boxTitle(head, "MYGKRELLM");
    for (int i = 1; i < 4; i += 1)
        mvwprintw(head, i, 5, "> %s :", "Os Name");
    for (int i = 1; i < 4; i += 1)
        mvwprintw(head, i, width / 2, "> %s :", "Os Next");
    wrefresh(head);
}