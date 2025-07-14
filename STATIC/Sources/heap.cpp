#include <bits/stdc++.h>
#include "../Headers/heap.h"
#include "../Headers/char.h"

using namespace std;

void STATIC::Heap::init(int size)
{
    a = new Char[size + 1];
    n = 0;
}

void STATIC::Heap::Heap_Up(int ind)
{
    while(ind > 1 && a[ind / 2] < a[ind])
    {
        swap(a[ind / 2] , a[ind]);
        ind /= 2;
    }
}

void STATIC::Heap::Heap_Down(int ind)
{
    do 
    {
        if(ind * 2 > n) break;
        int son = ind * 2;
        if(son + 1 <= n && a[son] < a[son + 1]) son++;
        if(a[son] < a[ind]) break;
        swap(a[son] , a[ind]);
        ind = son;
    }while(1);
}

void STATIC::Heap::add(Char x)
{
    a[++n] = x;
    Heap_Up(n);
}

STATIC::Char STATIC::Heap::get()
{
    return a[1];
}

void STATIC::Heap::pop()
{
    a[1] = a[n--];
    Heap_Down(1);
}

void STATIC::Heap::print()
{
    cout << '\n';
    for(int i = 1 ; i <= n ; i++) cout << a[i].ch;
    cout << '\n';
}

int STATIC::Heap::size()
{
    return n;
}