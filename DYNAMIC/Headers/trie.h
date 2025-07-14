#pragma once 

#include <bits/stdc++.h>
#include "list.h"

using namespace std;

class Text;

namespace DYNAMIC
{
    class Trie 
    {
        private:
            Trie *ch[2];
            Trie *parent;
            ListNode *lst;
            bool bit;
            bool escaped;
            int fr;
            char c;

        public:
            Trie(char c , Trie *&esc , vector < List > &lsts);
            Trie();
            string compute();
        friend class Text;
        friend void swap(Trie *x , Trie *y);
    };

    void swap(Trie *x , Trie *y);
}
