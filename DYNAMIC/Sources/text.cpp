#include <bits/stdc++.h>
#include "../Headers/text.h"
#include "../Headers/trie.h"

using namespace std;

DYNAMIC::Text::Text()
{
   R = new Trie(0 , startChar[0] , lsts);
}

void DYNAMIC::Text::process(char c)
{
  // cout << c << ' '; fflush(stdout);
   if(startChar.count(c) == 0) encoded += startChar[0] -> compute() + ascii(c);
   else encoded += startChar[c] -> compute();
 
   //cout << c << ' '; fflush(stdout);
   if(startChar.count(c) == 0) startChar[c] = new Trie(c , startChar[0] , lsts);
   update(startChar[c]);
   text += c;
}

void DYNAMIC::Text::update(Trie *node)
{
   while(node != nullptr)
   {
      //cout << 1 << ' '; fflush(stdout);
      //cout << node << ' '; fflush(stdout);

      int fr = node -> fr;
      ListNode *l = node -> lst;

      node -> fr++;

      if(l -> get() -> parent == lsts[fr].endd() -> get())
      {
         //cout << 2 << ' '; fflush(stdout);
         if(fr + 1 == lsts.size()) {List aux; lsts.push_back(aux);}
         lsts[fr].move_front(lsts[fr + 1] , node -> parent -> lst);
         lsts[fr].move_front(lsts[fr + 1] , l);
         node = node -> parent;
         node -> fr++;
         node = node -> parent;
         continue;
      }
      else if(lsts[fr].checkEnd(l))
      {

        //cout << 3 << ' '; fflush(stdout);

         if(fr + 1 == lsts.size()) {List aux; lsts.push_back(aux);}
         lsts[fr].move_front(lsts[fr + 1] , l);
         node = node -> parent;
         continue;
      }

      //cout << 4 << ' '; fflush(stdout);

     // if(lsts.size() > 2) cout << lsts[1].endd() -> get() -> c << endl ; fflush(stdout);

      ListNode *prv = l -> prev();
      ListNode *end = lsts[fr].endd();
      
      if(fr + 1 == lsts.size()) {List aux; lsts.push_back(aux);}
      lsts[fr].move_front(lsts[fr + 1] , l);
      lsts[fr].remove(end);
      lsts[fr].insert(end , prv);

      //cout << 5 << ' '; fflush(stdout);

      if(l -> get() -> parent != end -> get())
      {

         //cout << 6 << ' '; fflush(stdout);
        // cout << l -> get() -> parent << endl << end -> get() << endl << lsts[fr].begin() -> get() << endl;

         swap(l -> get() , end -> get());

         //cout << 8 << ' ' << end -> get() -> c ; fflush(stdout);
      } 

      node = node -> parent;
   }

   //cout << "\nDONE\n";

}

string DYNAMIC::Text::ascii(char c)
{
   string res;

   //cout << c <<' ' << "asdfasdfasd" << endl;
   for(int b = 7 ; b >= 0 ; b--)
   {
      res += '0' + (c >> b & 1);
   }

   return res;
}

string DYNAMIC::Text::getEncodedd()
{
   return encoded;
}

string DYNAMIC::Text::getText()
{
   return text;
}

void DYNAMIC::Text::printAlpha()
{
   int sum = 0;
   long double avg = 0;

   for(auto i : startChar)
   {
      cout << i.first << " " << i.second -> fr << " " << i.second -> compute() << endl;
      sum += i.second -> fr;
      avg += i.second -> compute().size() * ((long double) i.second -> fr / (long double) text.size());
   }

   if(sum != text.size()) cout << "wrong";
   cout << "Average number of bits: " << avg << '\n';
   cout << '\n';
}