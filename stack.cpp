#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack() {
    top1 = -1;
    top2 = 12;
}

Card Stack::Top(bool left) {
    if (left) {
        return entry[top1];
    }
    return entry[top2];
}

Card Stack::Position(bool left, int i) {
    Card empty;
    if (left) {
        if (i > top1) {
            return empty;
        }
        return entry[i];
    }
    if (12 + i > top2) {
        return empty;
    }
    return entry[12 + i];
}

void Stack::Push(bool left, Card card) {
    if (Full(left)) {
        cout << "Pilha Cheia";
        abort();
    }

    if (left) {
        top1++;
        entry[top1] = card;
        return;
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
        return;
    }
    top2--;
}

bool Stack::Empty(bool left) {
    if (left) {
        return (top1 == -1);
    }
    return (top2 == 12);
}

bool Stack::Full(bool left) {
    if (left) {
        return (top1 == MaxStack - 1);
    }
    return (top2 == MaxStack * 2 - 1);
}

int Stack::Size(bool left) {
    if (left) {
        return top1 + 1;
    }
    return top2 - 12;
}