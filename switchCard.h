#ifndef SWITCHCARD_H // updated all libraries as of 30th April 2023
#define SWITCHCARD_H

#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

class Switch {
public:
    Switch(int numPlayers, int numCards);
    void play();

private:
    struct Card {
        string face;
        string suit;
    };

    vector<Card> createDeck();
    void shuffleDeck();
    void dealCards();
    void printHand(const vector<Card>& hand);
    int getCardValue(const Card& card);
    void swapCards(vector<Card>& hand, int cardIndex);
    int scoreHand(const vector<Card>& hand);

    const int numPlayers;
    const int numCards;
    vector<Card> deck;
    vector<vector<Card>> hands;
};


#endif
