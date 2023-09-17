#ifndef card_h
#define card_h
#include <string>

using namespace std;

class Card{
    public:
    Card(int naipe = 0, int num = 0);
    int GetNum();
    int GetNaipe();
    int GetColor();
    bool EmptyCard();
    void Clear();
    private:
    int num = 0;
    int naipe = 0;
};

#endif