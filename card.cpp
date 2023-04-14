#include "card.h"

Card::Card(int suit, int rank)
    : suit_(suit), rank_(rank) {}

int Card::get_suit() const {
    return suit_;
}

int Card::get_rank() const {
    return rank_;
}

string Card::display() const {
    string suit;
    string rank;
    switch (suit_) {
        case HEARTS:
            suit = "HEARTS ♥";
            break;
        case DIAMONDS:
            suit = "DIAMONDS ♦";
            break;
        case CLUBS:
            suit = "CLUBS ♣";
            break;
        case SPADES:
            suit = "SPADES ♠";
            break;
    }
    switch (rank_) {
        case TWO:
            rank = "2 (DEE)";
            break;
        case THREE:
            rank = "3";
            break;
        case FOUR:
            rank = "4";
            break;
        case FIVE:
            rank = "5";
            break;
        case SIX:
            rank = "6";
            break;
        case SEVEN:
            rank = "7";
            break;
        case EIGHT:
            rank = "8";
            break;
        case NINE:
            rank = "9";
            break;
        case TEN:
            rank = "10";
            break;
        case JACK:
            rank = "J";
            break;
        case QUEEN:
            rank = "Q";
            break;
        case KING:
            rank = "K";
            break;
        case ACE:
            rank = "A";
            break;
    }
    return rank + "(" + suit + ")";
}
