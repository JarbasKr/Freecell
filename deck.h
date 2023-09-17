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
    Card GetStackTop(int i, bool left);
    Card GetStackByPosition(bool left, int i, int p);
    Card GetFreeCell(int i);
    void SetFreeCell(int i, Card card);
    void ShowGame();
    private:

    Card deck[DECK_SIZE]; // Baralho completo
    Stack stacks[STACK_SIZE]; // Pilhas
    Card freeCells[4]; // Free Cells
};

#endif