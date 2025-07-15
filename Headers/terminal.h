#pragma once

#include <bits/stdc++.h>    

using namespace std;

namespace TERMINAL
{
    string terminalColors[20];

    enum Colors
    {
        BLACK , RED , GREEN , YELLOW , BLUE , MAGENTA , CYAN , WHITE
    };

    void clear()
    {
        cout << "\033[3J\033[H\033[2J";
    }


    void compute_terminal_colors()
    {
        terminalColors[Colors::BLACK] = "\033[30m";
        terminalColors[Colors::RED]   = "\033[31m";
        terminalColors[Colors::GREEN] = "\033[32m";
        terminalColors[Colors::YELLOW]= "\033[33m";
        terminalColors[Colors::BLUE]  = "\033[34m";
        terminalColors[Colors::MAGENTA] = "\033[35m";
        terminalColors[Colors::CYAN] = "\033[36m";
        terminalColors[Colors::WHITE] = "\033[37m";
    }

    void change_color(int x)
    {
        cout << terminalColors[x];
    }

    void reset_color()
    {
        cout << "\033[0m";
    }

    void type_in_color(int x , string y)
    {
        change_color(x); cout << y;
        reset_color(); fflush(stdout);
    }
}