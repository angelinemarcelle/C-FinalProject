#ifndef SWITCHCARD_H // updated all libraries as of 30th April 2023
#define SWITCHCARD_H

#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

struct Cards {
    string face;
    string suit;
};

vector<Cards> createDeck();
void shuffleDeck(vector<Cards>& deck);
vector<vector<Cards> > dealCards(vector<Cards>& deck, int numPlayers, int numCards);
void printHand(const vector<Cards>& hand);
int getCardValue(const Cards& card);
void swapCards(vector<Cards>& hand, vector<Cards>& deck, int cardIndex);
int scoreHand(const vector<Cards>& hand);


#endif
