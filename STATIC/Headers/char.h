#include <bits/stdc++.h>
#pragma once 
#include "trie.h"

struct Char 
{
    char ch;
    int fr;
    Trie *node;

    bool operator < (Char b)
    {
        return fr >= b.fr;
    }

    Char(char ch , int fr) : ch(ch) , fr(fr) , node(new Trie(ch)) {}
    Char() : ch(0) , fr(-1) , node(nullptr) {}
};