#include <bits/stdc++.h>
#include "text.h"
#include "heap.h"
#include "char.h"

using namespace std;

Text::Text(string s)
{
    text = s;
    R = nullptr;
    process();
    build();
    encode();
}

void Text::process()
{
    for(auto i : text)
        ++fr[i];

    h.init(fr.size());

    for(auto i : fr)
    {
        Char curr = {i.first , i.second};
        alpha.push_back(curr);
        h.add(curr);
    }
}

void Text::build()
{
    while(h.size() > 1)
    {
        Char v2 = h.get(); h.pop();
        Char v1 = h.get(); h.pop();
        Char v0 = {0 , v1.fr + v2.fr};
        
       // cout << v1.ch << ' ' << v2.ch << '\n';

        v0.node -> ch[0] = v1.node;
        v0.node -> ch[1] = v2.node;
        
        v1.node -> par = v0.node;
        v2.node -> par = v0.node;
        
        v1.node -> bit = 0;
        v2.node -> bit = 1;
        
        h.add(v0);
    }

    R = h.get().node;

    for(auto &i : alpha)
    {
        f[i.ch] = construct(i.node);
        //cout << f[i.ch] << '\n';
    }
}

string Text::construct(Trie *node)
{
    string res;

    while(node -> par != nullptr)
    {
        res += node -> bit + '0';
        node = node -> par;
    }   

    reverse(res.begin() , res.end());
    return res;
}

void Text::encode()
{
    for(auto ch : text)
        base += f[ch];

    encoded = base;
    encoded += "#";

    for(auto i : fr)
    {
        encoded += i.first;
        encoded += "#";
        encoded += transform(i.second);
        encoded += "#";
    }
}

string Text::transform(int x)
{
    if(x == 0) return "0";
    string res = "";
    while(x){res += x % 10 + '0' ; x /= 10 ; }
    return res;
}

string Text::get()
{
    return encoded;
}