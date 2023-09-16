#ifndef card_h
#define card_h
#include <string>

using namespace std;

class Card{
    public:
    // ~Carta(
    Card(int num = 0, int naipe = 0);
    int GetNum();
    int GetNaipe();
    int GetColor();
    bool EmptyCard();
    private:
    int num = 0;
    int naipe = 0;
    // int cor;
};

#endif