#include "card.h"

class Deck {

public:
    Deck();
    void shuffle();
    Card draw();

private:
    Card cards[52];
    int card_val;
    const int HEARTS = 0;
    const int DIAMONDS = 1;
    const int CLUBS = 2;
    const int SPADES = 3;
    const int TWO = 2;
    const int THREE = 3;
    const int FOUR = 4;
    const int FIVE = 5;
    const int SIX = 6;
    const int SEVEN = 7;
    const int EIGHT = 8;
    const int NINE = 9;
    const int TEN = 10;
    const int JACK = 11;
    const int QUEEN = 12;
    const int KING = 13;
    const int ACE = 14;
};
