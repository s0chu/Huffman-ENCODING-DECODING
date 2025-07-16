#pragma once

#include <bits/stdc++.h>    

using namespace std;

namespace TERMINAL
{
    //string terminalColors[20];
    extern string terminalColors[20];

    enum Colors
    {
        BLACK , RED , GREEN , YELLOW , BLUE , MAGENTA , CYAN , WHITE
    };

    void clear();
    void compute_terminal_colors();
    void change_color(int x);
    void reset_color();

    template < class T >
    void type_in_color(int x , T y)
    {
        change_color(x); cout << y;
        reset_color(); fflush(stdout);
    }
}