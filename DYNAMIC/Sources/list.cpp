#include <bits/stdc++.h>
#include "../Headers/list.h"

using namespace std;

void List::push_back(ListNode *x)
{
    if(counter == 0)
    {
        beg = end = x;
        counter++;
        return;
    }

    end -> nxt = x;
    x -> prv = end;
    end = x;
    counter++;
}

void List::push_front(ListNode *x)
{
    if(counter == 0)
    {
        beg = end = x;
        counter++;
        return;
    }

    beg -> prv = x;
    x -> nxt = beg;
    beg = x;
    counter++;
}

void List::remove(ListNode *x)
{
    if(x == beg) 
    {
        if(counter == 1) beg = end = nullptr;
        else beg = beg -> nxt;
    }
    else if(x == end)
    {
        if(counter == 1) beg = end = nullptr;
        else end = end -> prv;
    }
    else 
    {
        x -> prv -> nxt = x -> nxt;
        x -> nxt -> prv = x -> prv;
    }

    x -> prv = x -> nxt = nullptr;
    counter--;
}

void List::move_back(List &l , ListNode *x)
{
    remove(x);
    l.push_back(x);
}

void List::move_front(List &l , ListNode *x)
{
    remove(x);
    l.push_front(x);
}

void List::insert(ListNode *x , ListNode *prv)
{
    if(prv == nullptr) 
        push_front(x);
    else if(prv == end)
        push_back(x);
    else 
    {
        x -> prv = prv;
        x -> nxt = prv -> nxt;
        x -> prv -> nxt = x;
        x -> nxt -> prv = x;
        counter++;
    }
}

int List::size()
{
    return counter;
}

bool List::checkBeg(ListNode *x)
{
    return x == beg;
}

bool List::checkEnd(ListNode *x)
{
    return x == end;
}

ListNode* List::begin()
{
    return beg;
}

ListNode* List::endd()
{
    return end;
}

ListNode* ListNode::prev()
{
    return prv;
}

ListNode* ListNode::next()
{
    return nxt;
}

Trie* ListNode::get()
{
    return tr;
}