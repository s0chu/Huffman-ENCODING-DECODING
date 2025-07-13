#pragma once 

#include <bits/stdc++.h>
#include "list.h"

using namespace std;

class Trie 
{
    private:
        Trie *ch[2];
        Trie *parent;
        bool bit;
        List *lst;
};