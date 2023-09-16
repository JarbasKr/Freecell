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

    cout << "A movimentação das cartas segue as seguintes regras:\n"
            << "  - Uma pilha de saída recebe cartas em ordem imediatamente crescente,\n"
            << "    do Ás ao Rei, todas do mesmo naipe.\n"
            << "  - Uma pilha de jogo recebe cartas com naipes de cores alternantes em\n"
            << "    ordem imediatamente decrescente.\n"
            << "  - Uma free cell recebe qualquer carta desde que não esteja já ocupada.\n"
            << "  - Toda carta de uma pilha de jogo é movida de seu topo e para ele.\n\n";

    cout << "Para jogar, insira o índice de onde quer tirar uma carta seguido de um espaço e o índice de onde quer colocá-la.\n"
            << "Por exemplo, se quiser mover a carta do topo da pilha 4 para a free cell 10, insira: 4 10.\n\n"
            << "O jogo é ganho quando todas as pilhas de saída forem preenchidas. Note que o estado inicial do jogo\n"
            << "é aleatório, portanto talvez não haja uma solução.\n\n";

    cout << "Naipes pretos: Espadas e Paus\n"
            << "Naipes vermelhos: Ouro e Copas\n\n";
    
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

    bool left = false;
    int localI = (i - 1) % 2;

    // Pilhas principais
    if (i >= 1 && i <= 8) {
        if (localI % 2 == 0) {
            localI = (localI % 2) - 1;
            left = true;
        }
        return deck.GetStackTop(localI, left);
    }

    // FreeCells
    if (i >= 9 && i <= 12) {
        return deck.GetFreeCell(i - 9);
    }

    return invalidCard;
}

bool isValidMove(Deck deck, Card card, int destiny) {
    // Movimento para as Pilhas principais
    if (destiny >= 1 && destiny <= 8) {
        Card destinyTopCard;
        destinyTopCard = getValue(deck, destiny);

        // P = 1
        // E = 2
        // C = 3
        // O = 4

        // Deve verificar se pode ser adicionado à respectiva pilha
        if (destinyTopCard.GetNum() > card.GetNum()) {
            if (destinyTopCard.GetNaipe() == 1 || destinyTopCard.GetNaipe() == 2) {
                return card.GetNaipe() == 3 || card.GetNaipe() == 4;
            }
            return card.GetNaipe() == 1 || card.GetNaipe() == 2;
        }
    }

    // TODO: Validação de movimento nas FreeCells
}

int main() {
    Deck deck;
    string input;

    Card originCard;

    bool isValidInput = false;
    int origin, destiny;

    // cout << "START" << endl;

    // Preenche o baralho com as 52 cartas
    deck.Fill();

    // Distribui as cartas nas 6 pilhas
    deck.Distribute();

    // Mostra o MENU
    showInstructions();
    
    while (true) {
        readInput(&input, &isValidInput, &origin, &destiny);
        if (isValidInput) {
            if (origin == destiny) {
                cout << "A origem da carta não pode ser igual ao destino" << endl;
                continue;
            }

            if (origin < 1 || origin > 12) {
                cout << "Origem inválida!";
                continue;
            }

            if (destiny < 1 || destiny > 12) {
                cout << "Destino inválido!";
                continue;
            }

            cout << "Input Okay" << endl;
            originCard = getValue(deck, origin);

            if (!originCard.EmptyCard()) {
                isValidMove(deck, originCard, destiny);
            }
        }
    }

    cout << "Parabens, tú venceu miserável" << endl;

    return 0;
}