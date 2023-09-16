#include <iostream>
#include <ctime>

#include "deck.h"
#include "stack.h"

using namespace std;

void Deck::Fill(){
    // cout << "BARALHO:PREENCHER" << endl;

    // P = 1
    // E = 2
    // C = 3
    // O = 4

    int count = 0;
    for(int i = 1;i < 5;i++){
        for(int j = 1;j < 14;j++){
            Card novaCarta(i, j);
            // cout << "BARALHO:PREENCHENDO " << i << " " << j << endl;
            deck[count] = novaCarta;
            // cout << novaCarta.GetNum() << endl;
            count++;
        }
        Card freeCellEmptyCard;
        freeCells[i] = freeCellEmptyCard;
    }

    // cout << "BARALHO:PREENCHIDO" << endl;

    // for (int i = 0; i < 52; i++) {
    //     cout << deck[i].GetNum() << endl;
    // }
};

void Deck::Distribute() {
    srand(time(0));

    int c = 52;

    for (int s = 0; s < STACK_SIZE; s++) {
        Stack stack;
        stacks[s] = stack;
        // cout << s << endl;
    }

    for (int i = 0; i < c; i++) {
        int index;
        bool left;

        do {
            index = rand() % 4;
            left = rand() % 2;
        } while(stacks[index].Full(left));
        
        stacks[index].Push(left, deck[i]);
        // TODO: Precisa concertar a distribuição
        // cout << "I: " << i << endl;
        // cout << "NA: " << deck[i].GetNaipe() << endl;
        // cout << "NU: " << deck[i].GetNum() << endl;
        // cout << endl;
    }

    // cout << "###" << endl;

    // cout << stacks[0].Top(false).GetNum() << endl;
    // cout << stacks[0].Top(false).GetNaipe() << endl;
    // cout << endl;
    // cout << stacks[0].Top(true).GetNum() << endl;
    // cout << stacks[0].Top(true).GetNaipe() << endl;
    // cout << endl;

    // cout << stacks[1].Top(false).GetNum() << endl;
    // cout << stacks[1].Top(false).GetNaipe() << endl;
    // cout << endl;
    // cout << stacks[1].Top(true).GetNum() << endl;
    // cout << stacks[1].Top(true).GetNaipe() << endl;
    // cout << endl;

    // cout << stacks[2].Top(false).GetNum() << endl;
    // cout << stacks[2].Top(false).GetNaipe() << endl;
    // cout << endl;
    // cout << stacks[2].Top(true).GetNum() << endl;
    // cout << stacks[2].Top(true).GetNaipe() << endl;
    // cout << endl;

    // cout << stacks[3].Top(false).GetNum() << endl;
    // cout << stacks[3].Top(false).GetNaipe() << endl;
    // cout << endl;
    // cout << stacks[3].Top(true).GetNum() << endl;
    // cout << stacks[3].Top(true).GetNaipe() << endl;
    // cout << endl;
}

Card Deck::GetStackTop(int i, bool left){
    return stacks[i].Top(left);
};

Card Deck::GetFreeCell(int i){
    return freeCells[i];
};

void Deck::SetFreeCell(int i, Card card){
    freeCells[i] = card;
};