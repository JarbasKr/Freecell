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

void Card::Clear(){
    num = 0;
    naipe = 0;
    return;
};