#pragma once 
#include <bits/stdc++.h>
#include "heap.h"
#include "trie.h"

using namespace std;

class Text 
{
    private:
        string text , encoded , base;
        map < char , int > fr;
        map < char , string > f;
        Heap h;
        Trie *R;
        vector < Char > alpha;

        void process();
        void build();
        void encode();
        string construct(Trie *node);
        string transform(int x);

    public: 
        Text(string x);
        string get();
};