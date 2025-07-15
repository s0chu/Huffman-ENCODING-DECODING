#include <bits/stdc++.h>    

#include "Headers/terminal.h"
#include "Headers/screens.h"

using namespace std;


int main()
{

    TERMINAL::compute_terminal_colors();
    SCREEN::cast_functions();
    SCREEN::printOnScreen[Screen::INPUT] = 0;
    
    while(1)
    {
        for(int i = 0 ; i < Screen::count ; i++)
            if(SCREEN::printOnScreen[i] == 0)
                SCREEN::fnc[i]();
    }

   
}