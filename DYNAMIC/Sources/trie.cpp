#include <bits/stdc++.h>
#include "../Headers/trie.h"
#include "../Headers/list.h"

using namespace std;

Trie::Trie()
{
    fr = 0;
    ch[0] = ch[1] = nullptr;
    parent = nullptr;
    escaped = 1;
    bit = 0;
    lst = new ListNode(this);
}

Trie::Trie(char c , Trie *&esc , vector < List > &lsts)
{
    //cout << c << endl;

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
        //cout << "start" << endl << endl << esc -> compute() << endl; fflush(stdout);
        if(fr == lsts.size()) {List aux; lsts.push_back(aux);}
        lsts[fr].push_front(esc -> lst);
        lsts[fr].insert(lst , esc -> lst);
    }

    
}

void swap(Trie *x , Trie *y)
{
    x -> parent -> ch[0] = (x -> parent -> ch[0] == x ? y : x -> parent -> ch[0]);
    x -> parent -> ch[1] = (x -> parent -> ch[1] == x ? y : x -> parent -> ch[1]);

    //cout << "blank" << endl;

    y -> parent -> ch[0] = (y -> parent -> ch[0] == y ? x : y -> parent -> ch[0]);
    y -> parent -> ch[1] = (y -> parent -> ch[1] == y ? x : y -> parent -> ch[1]);

    swap(x -> bit , y -> bit);
    //cout << endl << endl << x -> c << ' ' << y -> c << endl;
    std::swap(x -> parent , y -> parent);
}

string Trie::compute()
{
    Trie *node = this;
    string res;

    //cout << 1234; fflush(stdout);
    
    while(node -> parent != nullptr)
    {
        res += node -> bit + '0';
        node = node -> parent;
    }

   // cout << "DONEcompute" << endl;
    reverse(res.begin() , res.end());
    return res;
}