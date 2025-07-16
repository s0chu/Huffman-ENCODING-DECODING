#include <bits/stdc++.h>
#include "../Headers/trie.h"
#include "../Headers/list.h"

using namespace std;

DYNAMIC::Trie::Trie()
{
    fr = 0;
    ch[0] = ch[1] = nullptr;
    parent = nullptr;
    escaped = 1;
    bit = 0;
    lst = new ListNode(this);
}

DYNAMIC::Trie::Trie(char c , Trie *&esc , vector < List > &lsts)
{
    this -> c = c;

    if(c == 0)
    {
        fr = 0;
        ch[0] = ch[1] = nullptr;
        parent = nullptr;
        escaped = 1;
        bit = 0;
        lst = new ListNode(this);
        esc = this;

        if(fr == lsts.size()) {List aux; lsts.push_back(aux);}
        lsts[fr].push_back(lst);
    }
    else 
    {
        fr = 0;
        ch[0] = ch[1] = nullptr;
        parent = esc;
        bit = 1;
        escaped = 0;
        lst = new ListNode(this);
        
        esc -> ch[1] = this;
        esc -> ch[0] = new Trie();
        esc -> ch[0] -> parent = esc;
        esc -> ch[0] -> bit = 0;
        esc -> c = -1;
        esc -> escaped = 0;

        esc = esc -> ch[0];

        if(fr == lsts.size()) {List aux; lsts.push_back(aux);}
        lsts[fr].push_front(esc -> lst);
        lsts[fr].insert(lst , esc -> lst);
    }

    
}

void DYNAMIC::swap(Trie *x , Trie *y)
{
    x -> parent -> ch[0] = (x -> parent -> ch[0] == x ? y : x -> parent -> ch[0]);
    x -> parent -> ch[1] = (x -> parent -> ch[1] == x ? y : x -> parent -> ch[1]);

    y -> parent -> ch[0] = (y -> parent -> ch[0] == y ? x : y -> parent -> ch[0]);
    y -> parent -> ch[1] = (y -> parent -> ch[1] == y ? x : y -> parent -> ch[1]);

    std::swap(x -> bit , y -> bit);
    std::swap(x -> parent , y -> parent);
}

string DYNAMIC::Trie::compute()
{
    Trie *node = this;
    string res;

    while(node -> parent != nullptr)
    {
        res += node -> bit + '0';
        node = node -> parent;
    }

    reverse(res.begin() , res.end());
    return res;
}