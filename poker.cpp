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

    string to_string() const {
        string suit_str;
        string rank_str;
        switch (suit_) {
            case HEARTS:
                suit_str = "HEARTS";
                break;
            case DIAMONDS:
                suit_str = "DIAMONDS";
                break;
            case CLUBS:
                suit_str = "CLUBS";
                break;
            case SPADES:
                suit_str = "SPADES";
                break;
        }
        
        switch (rank_) {
            case TWO:
                rank_str = "2 (dee)";
                break;
            case THREE:
                rank_str = "3";
                break;
            case FOUR:
                rank_str = "4";
                break;
            case FIVE:
                rank_str = "5";
                break;
            case SIX:
                rank_str = "6";
                break;
            case SEVEN:
                rank_str = "7";
                break;
            case EIGHT:
                rank_str = "8";
                break;
            case NINE:
                rank_str = "9";
                break;
            case TEN:
                rank_str = "10";
                break;
            case JACK:
                rank_str = "J";
                break;
            case QUEEN:
                rank_str = "Q";
                break;
            case KING:
                rank_str = "K";
                break;
            case ACE:
                rank_str = "A";
                break;
        }
        return rank_str + "(" + suit_str + ")";
    }

private:
    int suit_;
    int rank_;
};
