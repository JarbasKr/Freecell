#include "card.h"

Card::Card(int novoNaipe, int novoNum){
    num = novoNum;
    naipe = novoNaipe;
};

int Card::getNum(){
    return num;
};

int Card::getNaipe(){
    return naipe;
};

// int Carta::getCor(){
//     return cor;
// };