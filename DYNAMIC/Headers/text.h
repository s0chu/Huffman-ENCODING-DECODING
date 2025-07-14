#pragma once
#include <bits/stdc++.h>
#include "list.h"
#include "trie.h"

using namespace std;

namespace DYNAMIC
{
    class Text 
    {
        private:
            vector < List > lsts;
            string encoded , text;
            Trie *R;
            map < char , string > f;
            map < char , Trie* > startChar;


            void update(Trie *node);
            string ascii(char c);

        public:
            Text();
            void process(char c);
            string getEncodedd();
            string getText();
            void printAlpha();
            //long double getAverageLen();
    };
}
