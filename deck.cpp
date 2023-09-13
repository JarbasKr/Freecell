#include <iostream>
#include <ctime>

#include "deck.h"
#include "stack.h"

using namespace std;

void Deck::Fill(){
    cout << "BARALHO:PREENCHER" << endl;

    // P = 1
    // E = 2
    // C = 3
    // O = 4

    int count = 0;
    for(int i = 1;i < 5;i++){
        for(int j = 1;j < 14;j++){
            Card novaCarta(i, j);
            cout << "BARALHO:PREENCHENDO " << i << " " << j << endl;
            deck[count] = novaCarta;
            cout << novaCarta.getNum() << endl;
            count++;
        }
    }

    cout << "BARALHO:PREENCHIDO" << endl;

    for (int i = 0; i < 52; i++) {
        cout << deck[i].getNum() << endl;
    }
};

void Deck::Distribute() {
    srand(0);

    int c = 52;

    for (int s = 0; s < STACK_SIZE + 1; s++) {
        Stack stack;
        stacks[s] = stack;
    }

    for (int i = 0; i < c; i++) {
        int index;
        bool left;

        do {
        index = rand() % 4;
        left = rand() % 2;
        } while(stacks[index].Full(left));
        
        stacks[index].Push(left, deck[i]);
    }

    cout << "###" << endl;

    cout << stacks[0].Top(false).getNum() << endl;
    cout << stacks[0].Top(true).getNum() << endl;

    cout << stacks[1].Top(false).getNum() << endl;
    cout << stacks[1].Top(true).getNum() << endl;

    cout << stacks[2].Top(false).getNum() << endl;
    cout << stacks[2].Top(true).getNum() << endl;

    cout << stacks[3].Top(false).getNum() << endl;
    cout << stacks[3].Top(true).getNum() << endl;
}