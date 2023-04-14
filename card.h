#include <string>
using namespace std;

class Card {
public:
    static const int HEARTS = 0, DIAMONDS = 1, CLUBS = 2, SPADES = 3;
    static const int TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10;
    static const int JACK = 11, QUEEN = 12, KING = 13, ACE = 14;
    Card(int suit, int rank); //constructor
    int get_suit() const; //getter
    int get_rank() const; //getter
    string display() const; // display function

private:
    int suit_;
    int rank_;
};
