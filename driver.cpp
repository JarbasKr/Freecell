#include <iostream>
#include <string>
#include <regex>
#include <sstream>

#include "deck.h"
#include "card.h"

using namespace std;

void showInstructions() {
    // Exibição do MENU
    cout << "--------------------------------- FREE CELL ---------------------------------\n";
    // TODO: Criar o menu
    
    return;
}

void readInput(string* input, bool* isValidInput, int* origin, int* destiny) {
    getline(cin, *input);
    *isValidInput = true;

    regex pattern(R"(\d+\s+\d+)");

    if (regex_match(*input, pattern)) {
        // Formato válido

        std::istringstream iss(*input);
        int num;

        bool addToOrigin = true;

        while (iss >> num) {
            if (addToOrigin) {
                *origin = num;
                addToOrigin = false;
                continue;
            }
            *destiny = num;
        }
    } else {
        // Formato inválido
        *isValidInput = false;
        cout << "Formato de entrada invalido, tente novamente" << endl;
    }

    return;
}

Card getValue(Deck deck, int i) {
    Card invalidCard;

    bool left = true;
    int localI = abs(i/2);

    if (i % 2 == 0) {
        localI = abs(i/2) - 1;
        left = false;
    }

    // Pilhas principais
    if (i >= 1 && i <= 8) {
        return deck.GetStackTop(localI, left);
    }

    // Pilhas de saída
    if (i >= 9 && i <= 12) {
        return deck.GetStackTop(localI, left);
    }

    // FreeCells
    if (i >= 13 && i <= 16) {
        return deck.GetFreeCell(i - 13);
    }

    return invalidCard;
}

bool isValidMove(Deck deck, Card card, int destiny) {
    // Movimento para as Pilhas principais

    cout << "\nCarta a ser movida: " << endl;
    cout << "NUM: " << card.GetNum() << ", NAIPE: " << card.GetNaipe() << endl << endl;

    if (destiny >= 1 && destiny <= 8) {
        Card destinyTopCard;
        destinyTopCard = getValue(deck, destiny);

        // P = 1 - Paus
        // E = 2 - Espadas
        // C = 3 - Copas
        // O = 4 - Ouros

        cout << "\nÚltima carta do topo: " << endl;
        cout << "NUM: " << destinyTopCard.GetNum() << ", NAIPE: " << destinyTopCard.GetNaipe() << endl << endl;

        // Deve verificar se pode ser adicionado à respectiva pilha
        if (destinyTopCard.GetNum() > card.GetNum()) {
            if (destinyTopCard.GetNaipe() == 1 || destinyTopCard.GetNaipe() == 2) {
                return card.GetNaipe() == 3 || card.GetNaipe() == 4;
            }
            return card.GetNaipe() == 1 || card.GetNaipe() == 2;
        }
    }

    // Validação de movimento nas FreeCells
    if (destiny >= 13 && destiny <= 16) {
        Card freeCell;
        freeCell = deck.GetFreeCell(destiny - 9);

        cout << "\nÚltima carta do topo: " << endl;
        cout << "NUM: " << freeCell.GetNum() << ", NAIPE: " << freeCell.GetNaipe() << endl << endl;

        // Se for uma carta vazia, o movimento é válido
        return freeCell.EmptyCard();
    }

    // Validação de movimento para as pilhas de saída
    if (destiny == 0) {
        Card lastOutCard;
        int destinyNaipe = 8 + card.GetNaipe();

        // Obtém a carta do topo da pilha de saída no respectivo naipe
        lastOutCard = getValue(deck, destinyNaipe);

        cout << "\nÚltima carta do topo: " << endl;
        cout << "NUM: " << lastOutCard.GetNum() << ", NAIPE: " << lastOutCard.GetNaipe() << endl << endl;
    }

    return false;
}

int main() {
    Deck deck;
    string input;

    Card originCard;

    bool isValidInput = false;
    bool isValid = false;
    int origin, destiny;

    // cout << "START" << endl;

    // Preenche o baralho com as 52 cartas
    deck.Fill();

    // Distribui as cartas nas 6 pilhas
    deck.Distribute();

    // Mostra o MENU
    // showInstructions();

    // Mostra o jogo
    
    while (true) {
        deck.ShowGame();
        readInput(&input, &isValidInput, &origin, &destiny);
        if (isValidInput) {
            if (origin == destiny) {
                cout << "A origem da carta não pode ser igual ao destino" << endl;
                continue;
            }

            if (origin < 1 || origin > 12) {
                cout << "Origem inválida!" << endl;
                continue;
            }

            if (destiny < 0 || destiny > 12) {
                cout << "Destino inválido!" << endl;
                continue;
            }

            originCard = getValue(deck, origin);

            if (!originCard.EmptyCard()) {
                isValid = isValidMove(deck, originCard, destiny);
                if (isValid) {
                    cout << "MOVIMENTO Okay" << endl;
                } else {
                    cout << "Esse movimento não é válido" << endl;
                }
            }
        }
    }

    cout << "Parabens, tú venceu miserável" << endl;

    return 0;
}