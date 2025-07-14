#pragma once 
#include <bits/stdc++.h>
#include "heap.h"
#include "trie.h"

using namespace std;

namespace STATIC 
{
    class Text 
    {
        private:
            string text , encoded , base;
            map < char , int > fr;
            map < char , string > f;
            Heap h;
            Trie *R;
            vector < Char > alpha;
            long double averageLen;

            void process();
            void build();
            void encode();
            string construct(Trie *node);
            string transform(int x);
            void decode();
            void calcAverageLen();
        public: 
            Text(string x);
            Text(string x , int t);
            string getEncoded();
            string getDecoded();
            long double getAverageLength();
            void printAlpha();
    };
}
