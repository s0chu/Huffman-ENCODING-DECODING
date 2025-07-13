#pragma once 
#include <bits/stdc++.h>
#include "char.h"

using namespace std;

class Heap 
{
    private:
        Char *a;
        int n;

    public:
        void init(int size);
        void Heap_Up(int ind);
        void Heap_Down(int ind);
        Char get();
        void pop();
        void add(Char x);
        void print();
        int size();
};
