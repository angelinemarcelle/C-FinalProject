#include <string>
#include <vector>
#include "card.h"

using namspace std;

class Player {
public:
    Player(string& name)
        : name_(name) {}

    string get_name() const {
        return name_;
    }

    void add_card(const Card& card) {
        deck_hold_.push_back(card);
    }

    int get_value() const {
        int value = 0;
        int ace_count = 0;
        for (const auto& card : deck_hold_) {
            int rank = card.get_rank();
            if (rank == ACE) {
                ace_count++;
                value += 11;
            } else if (rank >= TEN) {
                value += 10;
            } else {
                value += rank;
            }
        }
        while (value > 21 && ace_count > 0) {
            value -= 10;
            ace_count--;
        }
        return value;
    }

    void clear_deck_hold() {
        deck_hold_.clear();
    }

private:
    string name_;
    vector<Card> deck_hold_;
};
