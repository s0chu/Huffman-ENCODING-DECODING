#include <bits/stdc++.h>
#include "../Headers/text.h"
#include "../Headers/heap.h"
#include "../Headers/char.h"
#include "../../Headers/terminal.h"

using namespace std;

STATIC::Text::Text(string s)
{
    text = s;
    R = nullptr;
    process();
    build();
    calcAverageLen();
    encode();
}

void STATIC::Text::process()
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

void STATIC::Text::build()
{
    while(h.size() > 1)
    {
        Char v2 = h.get(); h.pop();
        Char v1 = h.get(); h.pop();
        Char v0 = {0 , v1.fr + v2.fr};

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
    }
}

string STATIC::Text::construct(Trie *node)
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

void STATIC::Text::encode()
{
    for(auto ch : text)
        base += f[ch];

    encoded = base;
    encoded += "#";

    for(auto i : fr)
    {
        encoded += transform(i.first);
        encoded += "#";
        encoded += transform(i.second);
        encoded += "#";
    }

    encoded.pop_back();
}

string STATIC::Text::transform(int x)
{
    if(x == 0) return "0";
    string res = "";
    while(x){res += x % 10 + '0' ; x /= 10 ; }
    reverse(res.begin() , res.end());
    return res;
}

string STATIC::Text::getEncoded()
{
    return encoded;
}

string STATIC::Text::getDecoded()
{
    return text;
}

STATIC::Text::Text(string encoded , int x) : encoded(encoded)
{
    int breakingPos = encoded.find('#');
    base = encoded.substr(0 , breakingPos);

    for( ; breakingPos != encoded.size() ; )
    {
        ++breakingPos;
        char ch = 0;

        for( ; encoded[breakingPos] != '#' ; breakingPos++)
            ch = ch * 10 + encoded[breakingPos] - '0';

        breakingPos++;
        int fr = 0; while(breakingPos < encoded.size() && encoded[breakingPos] != '#') {fr = fr * 10 + encoded[breakingPos++] - '0';}
        this -> fr[ch] = fr;
    }

    process();
    build();
    calcAverageLen();
    decode();
}

void STATIC::Text::decode()
{
    Trie *curr = R;

    for(int i = 0 ; i < base.size() ; i++)
    {
        curr = curr -> ch[base[i] - '0'];
        
        if(curr -> c != 0)
        {
            text += curr -> c;
            curr = R;
        }
    }
}

void STATIC::Text::calcAverageLen()
{
    int size = 0;

    for(auto i : fr)
        size += i.second;

    averageLen = 0;

    for(auto i : fr)
        averageLen += f[i.first].size() * ((long double) i.second / (long double) size);     
}

long double STATIC::Text::getAverageLength()
{
    return averageLen;
}

void STATIC::Text::printAlpha()
{
    for(auto i : fr)
    {
        TERMINAL::type_in_color(TERMINAL::Colors::RED , i.first); 
        cout << " ";
        TERMINAL::type_in_color(TERMINAL::Colors::WHITE , i.second); 
        cout << " ";
        TERMINAL::type_in_color(TERMINAL::Colors::CYAN , f[i.first]); 
        cout << '\n';
    }

    cout << "Average number of bits: "; 
    TERMINAL::type_in_color(TERMINAL::Colors::GREEN , averageLen);
    cout << '\n';

    cout << "Alpha size is: ";
    TERMINAL::type_in_color(TERMINAL::Colors::YELLOW , f.size());
    cout << '\n';
}