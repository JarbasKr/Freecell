#include <iostream>
#include "stack.h"

using namespace std;

Card Stack::Top(bool left) {
    if (left) {
        return entry[top1];
    }
    return entry[top2];
}

void Stack::Push(bool left, Card card) {
    if (Full(left)) {
        cout << "Pilha Cheia";
        abort();
    }

    if (left) {
        top1++;
        entry[top1] = card;
    }
    top2++;
    entry[top2] = card;
}

void Stack::Pop(bool left) {
    if (Empty(left)) {
        cout << "Pilha Vazia";
        abort();
    }

    if (left) {
        top1--;
    }
    top2--;
}

bool Stack::Empty(bool left) {
    if (left) {
        return (top1 == 0);
    }
    return (top2 == 0);
}

bool Stack::Full(bool left) {
    if (left) {
        return (top1 == MaxStack);
    }
    return (top2 == MaxStack);
}
