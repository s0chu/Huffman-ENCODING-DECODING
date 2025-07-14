#pragma once 

#include <bits/stdc++.h>
//#include "trie.h"

using namespace std;

namespace DYNAMIC 
{
    class Trie;

    class ListNode 
    {
        private:
            ListNode *prv , *nxt;
            Trie *tr;

        public:
            ListNode(Trie *node) : prv(nullptr) , nxt(nullptr) , tr(node) {}
            ListNode* prev();
            ListNode* next();
            Trie* get();

        friend class List;
    };

    class List 
    {
        private:
            ListNode *beg , *end;
            int counter;

        public:
            List() : beg(nullptr) , end(nullptr) , counter(0) {}
            void push_back(ListNode *x);
            void push_front(ListNode *x);
            void remove(ListNode *x); ///nu dealoca
            void insert(ListNode *x , ListNode *prv);
            void move_front(List &l , ListNode *x);
            void move_back(List &l , ListNode *x);
            int size();
            bool checkEnd(ListNode *x);
            bool checkBeg(ListNode *x);
            ListNode* begin();
            ListNode* endd();
    };
}
