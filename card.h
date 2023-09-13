#ifndef card_h
#define card_h
#include <string>

using namespace std;

class Card{
    public:
    // ~Carta(
    Card(int num = 0, int naipe = 0);
    int getNum();
    int getNaipe();
    int getColor();
    private:
    int num;
    int naipe;
    // int cor;
};

#endif