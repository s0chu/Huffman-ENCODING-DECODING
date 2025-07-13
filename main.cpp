#include <bits/stdc++.h>    
#include "STATIC/Headers/text.h"
//#include "STATIC/heap.h"

using namespace std;

int main()
{
   Text t("Ana are mere 1 2 3 4 ###");
   cout << t.getEncoded() << '\n';
   Text T(t.getEncoded() , 0);
   cout << T.getDecoded() << '\n' << T.getAverageLength();
}