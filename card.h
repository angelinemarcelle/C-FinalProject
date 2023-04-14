#include <string>
using namespace std;

class Card {
public:
    Card(int suit, int rank); //constructor
    int get_suit() const; //getter
    int get_rank() const; //getter
    string display() const; // display function

private:
    int suit_;
    int rank_;
};
