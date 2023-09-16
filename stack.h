#ifndef stack_h
#define stack_h
#include "card.h"

using namespace std;

const int MaxStack = 13;
class Stack{
    public:
    // Stack();
    void Push(bool left, Card card);
    void Pop(bool left);
    Card Top(bool left);
    bool Empty(bool left);
    bool Full(bool left);
    private:
    int top1 = -1;
    int top2 = 12;
    Card entry[MaxStack * 2];
};

#endif