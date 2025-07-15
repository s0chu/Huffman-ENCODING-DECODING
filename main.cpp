#include <bits/stdc++.h>    
#include "STATIC/Headers/text.h"
#include "DYNAMIC/Headers/list.h"
#include "DYNAMIC/Headers/trie.h"
#include "DYNAMIC/Headers/text.h"

using namespace std;

void clear()
{
    cout << "\033[3J\033[H\033[2J";
}

string transform(string path)
{
    ifstream f(path);
    string line;
    string res;
    while(getline(f , line))
    {
        res += "\n" + line;
    }

    return res;
}

string terminalColors[20];

enum Colors
{
    BLACK , RED , GREEN , YELLOW , BLUE , MAGENTA , CYAN , WHITE
};

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

int main()
{

    DYNAMIC::Text f;
    string t = "abasdfasdfasdfdsafadsfadsfadseqrqewreqwrqqewrr ytrewyjbvcnvbnzxsadrwr";

    for(auto c : t) f.process(c);
    cout << f.getEncodedd() << endl;
    f.printAlpha();

    DYNAMIC::Text F(f.getEncodedd());
    cout << f.getDecoded();

    return 0;

    compute_terminal_colors();

    bool printChoices = 0;
    bool printOption1 = 1;
    bool printOption2 = 1;
    bool printSTATICconsole = 1;
    bool printSTATICfile = 1;
    bool printSTATICcoder = 1;
    bool printSTATICencoder = 1;
    bool printSTATICdecoder = 1;

    string text;

    while(1)
    {
        if(printChoices == 0)
        {
            printChoices = 1;
            clear();
            cout << "Choose: \n";
            cout << "1. STATIC\n";
            cout << "2. DYNAMIC\n";
            int option; cin >> option;
            
            if(option != 1 && option != 2)
            {
                cout << "\r Please enter a valid option\n" << flush;
                sleep(1);
                printChoices = 0;
                continue;
            }

            if(option == 1) printOption1 = 0;
            if(option == 2) printOption2 = 0;
        }

        if(printOption1 == 0)
        {
            printOption1 = 1;
            clear();
            cout << "Choose the method of input:\n" << flush;
            cout << "1. Console\n";
            cout << "2. File\n";
            cout << "3. Back\n";

            int option; cin >> option;

            if(option != 1 && option != 2 && option != 3)
            {
                clear();
                cout << "Please enter a valid option\n"; fflush(stdout);
                sleep(3);
                printOption1 = 0;
                continue;
            }

            if(option == 1) printSTATICconsole = 0;
            if(option == 2) printSTATICfile = 0;
            if(option == 3) printChoices = 0;
        }
    
        if(printSTATICconsole == 0)
        {
            printSTATICconsole = 1;
            clear();
            cout << "Please enter a string: ";
            change_color(Colors::RED);
            cin >> text; fflush(stdout);
            reset_color();
            fflush(stdout);
            printSTATICcoder = 0;
        }

        if(printSTATICfile == 0)
        {
            printSTATICfile = 1;
            clear();
            cout << "Please enter file: "; change_color(Colors::MAGENTA);
            string path; cin >> path; reset_color();
            
            if(-1 == access(path.c_str() , R_OK)) 
            {
                clear();
                cout << "Invalid file. Please enter an existing file"; fflush(stdout);
                sleep(3);
                printSTATICfile = 0;
                continue;
            }

            text = transform(path);
            printSTATICcoder = 0;
        }

        if(printSTATICcoder == 0)
        {
            printSTATICcoder = 1;
            clear();
            cout << "Choose: \n";
            cout << "1. ENCODING\n";
            cout << "2. DECODING\n";
            cout << "3. Back\n";

            int option; cin >> option;

            if(option != 1 && option != 2 && option != 3)
            {
                clear();
                cout << "Please enter a valid option\n"; fflush(stdout);
                sleep(3);
                printSTATICcoder = 0;
                continue;
            }

            if(option == 1) printSTATICencoder = 0;
            if(option == 2) printSTATICdecoder = 0;
            if(option == 3) printOption1 = 0;
        }

        if(printSTATICencoder == 0)
        {
            printSTATICencoder = 1;
            clear();
            STATIC::Text t(text);
            cout << "Huffman encoding of "; 
            change_color(Colors::RED);
            cout << text;
            reset_color();
            cout << " is ";
            change_color(Colors::CYAN);
            cout << t.getEncoded();
            reset_color();
            cout << '\n';

            cout << "Type "; type_in_color(Colors::GREEN , "R") ; cout << " for going home OR " ; type_in_color(Colors::YELLOW , "B") ; cout << " for going back\n";
            char ch; cin >> ch;
            
            if(ch == 'R') printChoices = 0;
            if(ch == 'B') printOption1 = 0;
        }

        if(printSTATICdecoder == 0)
        {
            printSTATICdecoder = 1;
            clear();
            STATIC::Text t(text , 0);
            cout << "Huffman decoding of ";
            change_color(Colors::CYAN);
            cout << t.getEncoded();
            reset_color();
            cout << " is ";
            change_color(Colors::RED);
            cout << t.getDecoded();
            reset_color();
            cout << '\n';

            cout << "Type "; type_in_color(Colors::GREEN , "R") ; cout << " for going home OR " ; type_in_color(Colors::YELLOW , "B") ; cout << " for going back\n";
            char ch; cin >> ch;
            
            if(ch == 'R') printChoices = 0;
            if(ch == 'B') printOption1 = 0;
            if(ch != 'R' && ch != 'B') printChoices = 0;
        }
    }

   
}