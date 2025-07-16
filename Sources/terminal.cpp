#include <bits/stdc++.h>
#include "../Headers/terminal.h"

using namespace std;

void TERMINAL::clear()
{
    cout << "\033[3J\033[H\033[2J";
}

string TERMINAL::terminalColors[20];

void TERMINAL::compute_terminal_colors()
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

void TERMINAL::change_color(int x)
{
    cout << terminalColors[x];
}

void TERMINAL::reset_color()
{
    cout << "\033[0m";
}

