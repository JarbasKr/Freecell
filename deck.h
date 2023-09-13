#ifndef deck_h
#define deck_h

#include "card.h"
#include "stack.h"

const int DECK_SIZE = 52;
const int STACK_SIZE = 6;

class Deck{
    public:
    // Baralho();
    // ~Baralho();
    void Fill();
    void Distribute();
    bool Empty();
    private:

    Card deck[DECK_SIZE];
    Stack stacks[STACK_SIZE];
};

#endif