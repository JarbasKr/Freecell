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
        return deck.GetStackTop(left, localI);
    }

    // Pilhas de saída
    if (i >= 9 && i <= 12) {
        return deck.GetStackTop(left, localI);
    }

    // FreeCells
    if (i >= 13 && i <= 16) {
        return deck.GetFreeCell(i - 13);
    }

    return invalidCard;
}

bool isValidMove(Deck deck, Card card, int destiny) {
    // Movimento para as Pilhas principais

    // cout << "\nCarta a ser movida: " << endl;
    // cout << "NUM: " << card.GetNum() << ", NAIPE: " << card.GetNaipe() << endl << endl;

    if (destiny >= 1 && destiny <= 8) {
        Card destinyTopCard;
        destinyTopCard = getValue(deck, destiny);

        // P = 1 - Paus
        // E = 2 - Espadas
        // C = 3 - Copas
        // O = 4 - Ouros

        // cout << "\nÚltima carta do topo: " << endl;
        // cout << "NUM: " << destinyTopCard.GetNum() << ", NAIPE: " << destinyTopCard.GetNaipe() << endl << endl;

        // Deve verificar se pode ser adicionado à respectiva pilha
        if (destinyTopCard.GetNum() > card.GetNum()) {
            if (destinyTopCard.GetNaipe() <= 2) {
                if (card.GetNaipe() >= 3) {
                    return true;
                }
                
            } else {
                if (card.GetNaipe() <= 2) {
                    return true;
                }
            }
            cout << "\nERRO: Os naipes são da mesma cor!" << endl;
        } else {
            cout << "\nERRO: O valor da carta na pilha de destino é maior que o da origem!" << endl;
        }
    }

    // Validação de movimento nas FreeCells
    if (destiny >= 13 && destiny <= 16) {
        Card freeCell;
        freeCell = deck.GetFreeCell(destiny - 13);

        // cout << "\nÚltima carta do topo: " << endl;
        // cout << "NUM: " << freeCell.GetNum() << ", NAIPE: " << freeCell.GetNaipe() << endl << endl;

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

void move(Deck deck, Card card, int origin, int destiny) {
    cout << "CARTA A SER MOVIDA) NUM: " << card.GetNum() << ", NAIPE: " << card.GetNaipe() << endl << endl;
    bool left = true;
    int originI = abs(origin/2);
    int destinyI = abs(destiny/2);

    // REMOÇÃO

    // Card cardToRemove;
    // Card cardToAdd;
    Card cardNewOriginTop;

    if (origin % 2 == 0) {
        originI = abs(origin/2) - 1;
        left = false;
    }

    // cardToRemove = getValue(deck, origin);
    // cout << "REMOVER) NUM: " << cardToRemove.GetNum() << ", NAIPE: " << cardToRemove.GetNaipe() << endl << endl;

    // cout << "CARTA DE ORIGEM) NUM: " << card.GetNum() << ", NAIPE: " << card.GetNaipe() << endl << endl;

    if (origin >= 1 && origin <= 8) {
        // cout << "Remoção:" << endl;
        // cout << originI << endl;
        // cout << left << endl;
        deck.RemoveStackTop(left, originI);
        cardNewOriginTop = deck.GetStackTop(left, originI);
        cout << "NOVA CARTA DO TOPO NA ORIGEM) NUM: " << cardNewOriginTop.GetNum() << ", NAIPE: " << cardNewOriginTop.GetNaipe() << endl << endl;
    }

    // if (origin >= 13 && origin <= 16) {
    //     Card empty;
    //     deck.SetFreeCell(origin - 13, empty);
    // }

    // cardToAdd = getValue(deck, destiny);
    // cout << "ADICIONAR DEPOIS DE) NUM: " << cardToAdd.GetNum() << ", NAIPE: " << cardToAdd.GetNaipe() << endl << endl;

    // // ADIÇÃO
    // left = true;

    // if (destiny % 2 == 0) {
    //     destinyI = abs(destiny/2) - 1;
    //     left = false;
    // }

    // if (destiny >= 1 && destiny <= 8) {
    //     deck.PushToStack(left, destinyI, card);
    // }

    // if (destiny >= 13 && destiny <= 16) {
    //     deck.SetFreeCell(destiny - 13, card);
    // }
}

int main() {
    Deck deck;
    string input;

    Card originCard, destinyCard;

    bool isValidInput = false;
    bool isValid = false;
    int origin, destiny;

    // Preenche o baralho com as 52 cartas
    deck.Fill();

    // Distribui as cartas nas 6 pilhas
    deck.Distribute();

    // Mostra o MENU
    showInstructions();
    
    while (true) {
        deck.ShowGame();
        readInput(&input, &isValidInput, &origin, &destiny);
        if (isValidInput) {
            if (origin == destiny) {
                cout << "A origem da carta não pode ser igual ao destino" << endl;
                continue;
            }

            if (origin < 1 && origin > 16 || origin >= 9 && origin <= 12) {
                cout << "Origem inválida!" << endl;
                continue;
            }

            if (destiny < 0 && destiny > 16 || destiny >= 9 && destiny <= 12) {
                cout << "Destino inválido!" << endl;
                continue;
            }

            originCard = getValue(deck, origin);
            destinyCard = getValue(deck, destiny);

            if (!originCard.EmptyCard()) {
                isValid = isValidMove(deck, originCard, destiny);
                if (isValid) {
                    cout << "MOVIMENTO Okay" << endl;
                    move(deck, originCard, origin, destiny);
                } else {
                    cout << "Resumindo: MOVIMENTO INVALIDO!\n" << endl;
                }
            }
        }
    }

    cout << "Parabens, tú venceu miserável" << endl;

    return 0;
}