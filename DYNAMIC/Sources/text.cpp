#include <bits/stdc++.h>
#include "../Headers/text.h"
#include "../Headers/trie.h"
#include "../../Headers/terminal.h"

using namespace std;

DYNAMIC::Text::Text()
{
   R = new Trie(0 , startChar[0] , lsts);
}

DYNAMIC::Text::Text(string x)
{
   encoded = x;
   R = new Trie(0 , startChar[0] , lsts);
   decode();
}

void DYNAMIC::Text::decode()
{
   Trie *node = R;

   cout << endl;

   for(int i = 0 ; i <= encoded.size() ; i++)
   {
      if(node -> escaped == 1)
      {
         char c = 0;

         for(int j = i ; j < i + 8 ; j++)
         {
            c = c * 2 + encoded[j] - '0';
         }

         startChar[c] = new Trie(c , startChar[0] , lsts);
         update(startChar[c]);
         text += c;
         i += 7;
         node = R;
      }
      else if(node -> c != -1)
      {
         char c = node -> c;
         text += c;
         update(startChar[c]);
         node = R;
         i--;
      }
      else 
      {
         node = node -> ch[encoded[i] - '0'];
      }
   }
}

void DYNAMIC::Text::process(char c)
{
   if(startChar.count(c) == 0) encoded += startChar[0] -> compute() + ascii(c);
   else encoded += startChar[c] -> compute();
 
   if(startChar.count(c) == 0) startChar[c] = new Trie(c , startChar[0] , lsts);
   update(startChar[c]);
   text += c;
}

void DYNAMIC::Text::update(Trie *node)
{
   while(node != nullptr)
   {
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
         if(fr + 1 == lsts.size()) {List aux; lsts.push_back(aux);}
         lsts[fr].move_front(lsts[fr + 1] , l);
         node = node -> parent;
         continue;
      }

      ListNode *prv = l -> prev();
      ListNode *end = lsts[fr].endd();
      
      if(fr + 1 == lsts.size()) {List aux; lsts.push_back(aux);}
      lsts[fr].move_front(lsts[fr + 1] , l);
      lsts[fr].remove(end);
      lsts[fr].insert(end , prv);


      if(l -> get() -> parent != end -> get())
      {
         swap(l -> get() , end -> get());
      } 

      node = node -> parent;
   }
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

string DYNAMIC::Text::getDecoded()
{
   return text;
}

void DYNAMIC::Text::printAlpha()
{
   int sum = 0;
   long double avg = 0;

   for(auto i : startChar)
   {
      TERMINAL::type_in_color(TERMINAL::Colors::RED , (i.first == 0 ? '0' : i.first)); 
      cout << " ";
      TERMINAL::type_in_color(TERMINAL::Colors::WHITE , i.second -> fr); 
      cout << " ";
      TERMINAL::type_in_color(TERMINAL::Colors::CYAN , i.second -> compute()); 
      cout << '\n';

      sum += i.second -> fr;
      avg += i.second -> compute().size() * ((long double) i.second -> fr / (long double) text.size());
   }

   cout << "Average number of bits: "; 
   TERMINAL::type_in_color(TERMINAL::Colors::GREEN , avg);
   cout << '\n';

   cout << "Alpha size is: ";
   TERMINAL::type_in_color(TERMINAL::Colors::YELLOW , startChar.size());
   cout << '\n';
}