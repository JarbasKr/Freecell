#include <iostream>
#include <sstream>
#include <ctime>

#include "deck.h"
#include "stack.h"

using namespace std;

void Deck::Fill(){
    // P = 1
    // E = 2
    // C = 3
    // O = 4

    int count = 0;
    for(int i = 1;i < 5;i++){
        for(int j = 1;j < 14;j++){
            Card novaCarta(i, j);
            deck[count] = novaCarta;
            // cout << "CARTA) NAIPE: " << novaCarta.GetNaipe() << ", NUM: " << novaCarta.GetNum() << endl;
            count++;
        }
        Card freeCellEmptyCard;
        freeCells[i] = freeCellEmptyCard;
    }
};

void Deck::Distribute() {
    srand(time(0));

    int c = 52;

    for (int s = 0; s < STACK_SIZE; s++) {
        Stack stack;
        stacks[s] = stack;
    }

    int count = 0;

    for (int i = 0; i < c; i++) {
        bool left;
        int t_index, d_index;

        do {
            t_index = rand() % 4;
            left = rand() % 2;
        } while(stacks[t_index].FullStack(left));

        do {
            d_index = rand() % 52;
        } while(deck[d_index].EmptyCard());
        
        stacks[t_index].Push(left, deck[d_index]);
        // cout << count << endl;
        // cout << "CARTA) NAIPE: " << deck[d_index].GetNaipe() << ", NUM: " << deck[d_index].GetNum() << endl;
        // cout << endl;
        deck[d_index].Clear();
        // count++;
    }

    for (int i = 0; i < 4; i++) {
        for (int s = 0; s < 2; s++) {
            Card top = stacks[i].Top(s);
            cout << "TOPO " << i + 1 <<" - LADO " << s << ") NAIPE: " << top.GetNaipe() << ", NUM: " << top.GetNum() << endl;
        }
    }
}

void Deck::PushToStack(bool left, int i, Card card){
    stacks[i].Push(left, card);
};

Card Deck::GetStackTop(bool left, int i){
    return stacks[i].Top(left);
};

void Deck::RemoveStackTop(bool left, int i){
    stacks[i].Pop(left);
};

Card Deck::GetStackByPosition(bool left, int i, int p){
    return stacks[i].Position(left, p);
};

Card Deck::GetFreeCell(int i){
    return freeCells[i];
};

void Deck::SetFreeCell(int i, Card card){
    freeCells[i] = card;
};

void Deck::ShowGame() {
    cout << "Pilhas de Saida" << endl;
    cout << "--------------------------\n" << endl;

    for (int i = 0; i < 4; i++) {
        Card freeCell;
        freeCell = GetFreeCell(i);
        if (!freeCell.EmptyCard()) {
            int naipe = freeCell.GetNaipe();
            int num = freeCell.GetNum();

            string naipeS;
            string numS;

            std::ostringstream stream;
            stream << " " << num;

            switch (naipe) {
                case 1: naipeS = "P"; break;
                case 2: naipeS = "E"; break;
                case 3: naipeS = "C"; break;
                default: naipeS = "O"; break;
            }

            switch (num) {
                case 10: numS = "10"; break;
                case 11: numS = "JK"; break;
                case 12: numS = "QN"; break;
                case 13: numS = "KG"; break;
                default: numS = stream.str(); break;
            }
            cout << "[" << numS << "|" << naipeS << "]";
        } else {
            cout << "[    ]";
        }
    }
    cout << endl;

    for (int x = 13; x < 17; x++) {
        cout << "  00  ";
    }
    cout << endl;

    cout << "\nFreeCells" << endl;
    cout << "--------------------------\n" << endl;

    // P = 1 - Paus
    // E = 2 - Espadas
    // C = 3 - Copas
    // O = 4 - Ouros

    for (int i = 0; i < 4; i++) {
        Card freeCell;
        freeCell = GetFreeCell(i);
        if (!freeCell.EmptyCard()) {
            int naipe = freeCell.GetNaipe();
            int num = freeCell.GetNum();

            string naipeS;
            string numS;

            std::ostringstream stream;
            stream << " " << num;

            switch (naipe) {
                case 1: naipeS = "P"; break;
                case 2: naipeS = "E"; break;
                case 3: naipeS = "C"; break;
                default: naipeS = "O"; break;
            }

            switch (num) {
                case 10: numS = "10"; break;
                case 11: numS = "JK"; break;
                case 12: numS = "QN"; break;
                case 13: numS = "KG"; break;
                default: numS = stream.str(); break;
            }
            cout << "[" << numS << "|" << naipeS << "]";
        } else {
            cout << "[    ]";
        }
    }
    cout << endl;

    for (int x = 13; x < 17; x++) {
        cout << "  " << x << "  ";
    }
    cout << endl;

    cout << "\nBaralho Principal" << endl;
    cout << "--------------------------\n" << endl;

    for (int p = 1; p < 14; p++) {
        for (int i = 0; i < 4; i++) {
            for(int s = 0; s < 2; s++) {
                Card top;
                if (s == 0) {
                    top = GetStackByPosition(true, i, p);
                } else {
                    top = GetStackByPosition(false, i, p);
                }

                if (!top.EmptyCard()) {
                    int naipe = top.GetNaipe();
                    int num = top.GetNum();

                    string naipeS;
                    string numS;

                    std::ostringstream stream;
                    stream << " " << num;

                    switch (naipe) {
                        case 1: naipeS = "P"; break;
                        case 2: naipeS = "E"; break;
                        case 3: naipeS = "C"; break;
                        default: naipeS = "O"; break;
                    }

                    switch (num) {
                        case 10: numS = "10"; break;
                        case 11: numS = "JK"; break;
                        case 12: numS = "QN"; break;
                        case 13: numS = "KG"; break;
                        default: numS = stream.str(); break;
                    }
                    cout << "[" << numS << "|" << naipeS << "]";
                } else {
                    cout << "[    ]";
                }
                cout << "     ";
            }
        }
        cout << endl;
    }

    for (int x = 1; x < 9; x++) {
        cout << "  ";
        cout << "0" << x;
        cout << "  ";
        cout << "     ";
    }

    cout << "\n\nMovimento: ";
}

