#include <bits/stdc++.h>    
//#include "STATIC/Headers/text.h"
#include "DYNAMIC/Headers/list.h"
#include "DYNAMIC/Headers/trie.h"
#include "DYNAMIC/Headers/text.h"

using namespace std;

int main()
{
    string t = "abbcc";

     Text f;

     for(auto c : t) f.process(c);

     cout << f.getEncodedd();
     cout << '\n' ;f.printAlpha();
    // Text r(t);
    // cout << r.getAverageLength(); 
}