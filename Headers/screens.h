#pragma once 

#include <bits/stdc++.h>
#include "terminal.h"
#include "../STATIC/Headers/text.h"
#include "../DYNAMIC/Headers/list.h"
#include "../DYNAMIC/Headers/trie.h"
#include "../DYNAMIC/Headers/text.h"

using namespace std;

enum Screen
{
    INPUT , CONSOLE , FILEE , CODING , ENCODING , DECODING , METHOD , STATICC , DYNAMICC , INFO , count
};

namespace SCREEN
{
    string text;
    vector < function < void () > > fnc(Screen::count);
    vector < bool > printOnScreen(Screen::count , 1);
    vector < bool > type(Screen::count);
    vector < STATIC::Text > staticTexts;
    vector < DYNAMIC::Text > dynamicTexts;

    void input()
    {
        TERMINAL::clear();
        printOnScreen[Screen::INPUT] = 1;
        cout << "Choose input method: \n";
        cout << "1. Console\n";
        cout << "2. File\n";
        cout << "3. Exit\n";

        int option; TERMINAL::change_color(TERMINAL::Colors::BLUE); cin >> option; TERMINAL::reset_color();

        if(option != 1 && option != 2 && option != 3)
        {
            TERMINAL::clear();
            cout << "Please enter a valid option\n"; fflush(stdout);
            sleep(2);
            printOnScreen[Screen::INPUT] = 0;
            return;
        }

        if(option == 1) printOnScreen[Screen::CONSOLE] = 0;
        if(option == 2) printOnScreen[Screen::FILEE] = 0;
        if(option == 3) {cout << "Come back :("; exit(0);}
    }   

    void console()
    {
        printOnScreen[Screen::CONSOLE] = 1;
        TERMINAL::clear();
        cout << "Enter text: "; TERMINAL::change_color(TERMINAL::Colors::RED); cin >> text; TERMINAL::reset_color();
        printOnScreen[Screen::CODING] = 0;
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

    void file()
    {
        printOnScreen[Screen::FILEE] = 1;
        TERMINAL::clear();
        string path;

        cout << "Enter file: "; TERMINAL::change_color(TERMINAL::Colors::MAGENTA); cin >> path; TERMINAL::reset_color();

        if(-1 == access(path.c_str() , R_OK)) 
        {
           TERMINAL::clear();
           cout << "Invalid file, please enter a valid one\n";
           sleep(3);
           printOnScreen[Screen::FILEE] = 0;
           return;
        }

        text = transform(path);
        printOnScreen[Screen::CODING] = 0;
    }

    void coding()
    {
        TERMINAL::clear();
        printOnScreen[Screen::CODING] = 1;
        cout << "Choose:\n";
        cout << "1. ENCODING\n";
        cout << "2. DECODING\n";
        cout << "3. BACK\n";

        int option; TERMINAL::change_color(TERMINAL::Colors::BLUE); cin >> option; TERMINAL::reset_color();

        if(option != 1 && option != 2 && option != 3) 
        {
            TERMINAL::clear();
            cout << "Please enter a valid option\n";
            sleep(3);
            printOnScreen[Screen::CODING] = 0;
            return;
        }

        type[Screen::ENCODING] = type[Screen::DECODING] = 0;

        if(option == 1) {type[Screen::ENCODING] = 1 , printOnScreen[Screen::METHOD] = 0;};
        if(option == 2) {type[Screen::DECODING] = 1 , printOnScreen[Screen::METHOD] = 0;};
        if(option == 3) printOnScreen[Screen::INPUT] = 0;
    }

    void handle_static()
    {
        type[Screen::STATICC] = 1;
        type[Screen::DYNAMICC] = 0;

        if(type[Screen::ENCODING] == 1) {STATIC::Text t(text); staticTexts.push_back(t);}
        if(type[Screen::DECODING] == 1) {STATIC::Text t(text , 0); staticTexts.push_back(t);}
    }

    void handle_dynamic()
    {
        type[Screen::STATICC] = 0;
        type[Screen::DYNAMICC] = 1;
        if(type[Screen::ENCODING] == 1) {DYNAMIC::Text t; for(auto c : text) t.process(c); dynamicTexts.push_back(t);}
        if(type[Screen::DECODING] == 1) {DYNAMIC::Text t(text); dynamicTexts.push_back(t);}
    }

    void method()
    {
        TERMINAL::clear();
        printOnScreen[Screen::METHOD] = 1;

        cout << "Choose method: \n";
        cout << "1. STATIC\n";
        cout << "2. DYNAMIC\n";
        cout << "3. BACK\n";

        int option; TERMINAL::change_color(TERMINAL::Colors::BLUE); cin >> option; TERMINAL::reset_color();

        if(option != 1 && option != 2 && option != 3) 
        {
            TERMINAL::clear();
            cout << "Please enter a valid option\n";
            sleep(3);
            printOnScreen[Screen::METHOD] = 0;
            return;
        }

        if(option == 1) {handle_static() , printOnScreen[Screen::INFO] = 0;}
        if(option == 2) {handle_dynamic() , printOnScreen[Screen::INFO] = 0;}
        if(option == 3) printOnScreen[Screen::CODING] = 0;
    }

    void end_of_program()
    {
        cout << "Type "; TERMINAL::type_in_color(TERMINAL::Colors::GREEN , "R") ; cout << " for going home OR " ; TERMINAL::type_in_color(TERMINAL::Colors::YELLOW , "B") ; cout << " for going back\n";
        char ch; TERMINAL::change_color(TERMINAL::Colors::BLUE); cin >> ch; TERMINAL::reset_color();
        
        if(ch != 'R' && ch != 'B') ch = 'R';
        if(ch == 'R') printOnScreen[Screen::INPUT] = 0;
        if(ch == 'B') printOnScreen[Screen::INFO] = 0;
    }

    void handle_info()
    {
        if(type[Screen::STATICC] == 1) staticTexts.back().printAlpha();
        if(type[Screen::DYNAMICC] == 1) dynamicTexts.back().printAlpha();

        end_of_program();
    }

    void info()
    {
        TERMINAL::clear();
        printOnScreen[Screen::INFO] = 1;

        cout << "Choose information: \n";
        cout << "1. Show encoding of the text provided\n";
        cout << "2. Show decoding of the text provided\n";
        cout << "3. Show code function and average number of bits\n";
        cout << "4. Back\n";

        int option; TERMINAL::change_color(TERMINAL::Colors::BLUE); cin >> option; TERMINAL::reset_color();

        if(option != 1 && option != 2 && option != 3 && option != 4) 
        {
            TERMINAL::clear();
            cout << "Please enter a valid option\n";
            sleep(3);
            printOnScreen[Screen::METHOD] = 0;
            return;
        }

        if(option == 1) printOnScreen[Screen::ENCODING] = 0;
        if(option == 2) printOnScreen[Screen::DECODING] = 0;
        if(option == 3) handle_info();
        if(option == 4) printOnScreen[Screen::METHOD] = 0;
    }



    void encoding()
    {
        TERMINAL::clear();
        printOnScreen[Screen::ENCODING] = 1;
        
        #define get_text_encoding (type[Screen::STATICC] == 1 ? staticTexts.back().getEncoded() : dynamicTexts.back().getEncodedd())
        #define get_text_decoding (type[Screen::STATICC] == 1 ? staticTexts.back().getDecoded() : dynamicTexts.back().getDecoded())

        cout << "Huffman encoding of "; TERMINAL::type_in_color(TERMINAL::Colors::RED , get_text_decoding); 
        cout << " is "; TERMINAL::type_in_color(TERMINAL::Colors::CYAN , get_text_encoding); cout << "\n";

        end_of_program();
    }

    void decoding()
    {
        TERMINAL::clear();
        printOnScreen[Screen::DECODING] = 1;
        
        #define get_text_encoding (type[Screen::STATICC] == 1 ? staticTexts.back().getEncoded() : dynamicTexts.back().getEncodedd())
        #define get_text_decoding (type[Screen::STATICC] == 1 ? staticTexts.back().getDecoded() : dynamicTexts.back().getDecoded())

        cout << "Huffman decoding of "; TERMINAL::type_in_color(TERMINAL::Colors::CYAN , get_text_encoding); 
        cout << " is "; TERMINAL::type_in_color(TERMINAL::Colors::RED , get_text_decoding); cout << "\n";

        end_of_program();
    }

    void cast_functions()
    {
        ///INPUT , CONSOLE , FILEE , CODING , ENCODING , DECODING , METHOD , STATIC , DYNAMIC , INFO , count
        fnc[Screen::INPUT] = input;
        fnc[Screen::CONSOLE] = console;
        fnc[Screen::FILEE] = file;
        fnc[Screen::CODING] = coding;
        fnc[Screen::ENCODING] = encoding;
        fnc[Screen::DECODING] = decoding;
        fnc[Screen::METHOD] = method;
        fnc[Screen::INFO] = info;
    }
}