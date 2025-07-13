#pragma once 

#include <bits/stdc++.h>

using namespace std;

struct Trie 
{
    Trie *ch[2];
    Trie *par;
    bool bit;
    char c;

    Trie(char c) : c(c)
    {
        ch[0] = ch[1] = par = nullptr;
        bit = 0;
    }
};
