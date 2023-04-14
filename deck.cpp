#include "deck.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Deck::Deck() {
    int i = 0;
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int rank = TWO; rank <= ACE; rank++) {
            cards[i++] = Card(suit, rank);
        }
    }
    card_val = i - 1;
}

void Deck::shuffle() {
    srand(time(nullptr));
    for (int i =  51; i > 0; i--) {
        int j = rand() % (i + 1);
        Card t = cards_[i];
        cards_[i] = cards_[j];
        cards_[j] = t;
    }
}

Card Deck::draw() {
    return cards[card_val--];
}
