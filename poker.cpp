#include <iostream>
#include <string>
using namespace std;

class Card {
public:
    static const int HEARTS = 0, DIAMONDS = 1, CLUBS = 2, SPADES = 3;
    static const int TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10;
    static const int JACK = 11, QUEEN = 12, KING = 13, ACE = 14;

    Card(int suit, int rank)
            : suit_(suit), rank_(rank) {} //constructor

    int get_suit() const {
        return suit_; //getter
    } 

    int get_rank() const {
        return rank_; //getter
    }

    string display() const { //display function
        string suit;
        string rank;
        switch (suit_) {
            case HEARTS:
                suit = "HEARTS";
                break;
            case DIAMONDS:
                suit = "DIAMONDS";
                break;
            case CLUBS:
                suit = "CLUBS";
                break;
            case SPADES:
                suit = "SPADES";
                break;
        }
        
        switch (rank_) {
            case TWO:
                rank = "2 (dee)";
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

private:
    int suit_;
    int rank_;
};
