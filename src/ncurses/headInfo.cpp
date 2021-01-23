/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** headInfo
*/
#include "ncurses.hpp"

void headInfo()
{
    int height = 10;
    int width = 100;
    int top = 1;
    int left = 1;

    WINDOW *head = newwin(height, width, top, left);
    refresh();

    box(head, 0, 0);
    mvwprintw(head, 0, 2, "MY GKRELLM");
    for (int i = 2; i < 10; i += 2)
        mvwprintw(head, i, 5, "> %s :", "Os Name");
    for (int i = 2; i < 10; i += 2)
        mvwprintw(head, i, 50, "> %s :", "Os NExt");
    wrefresh(head);
}