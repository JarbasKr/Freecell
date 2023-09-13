#include <iostream>
#include "deck.h"

using namespace std;

int main() {
    Deck deck;

    cout << "START" << endl;

    // Preenche o baralho com as 52 cartas
    deck.Fill();

    // Distribui as cartas nas 8 pilhas
    deck.Distribute();

    cout << "END" << endl;

    return 0;
}