#include "card.h"

Card::Card(int novoNaipe, int novoNum){
    num = novoNum;
    naipe = novoNaipe;
};

int Card::GetNum(){
    return num;
};

int Card::GetNaipe(){
    return naipe;
};

bool Card::EmptyCard(){
    return !num || !naipe;
};

// int Carta::getCor(){
//     return cor;
// };