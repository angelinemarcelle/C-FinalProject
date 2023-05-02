#ifndef FOURTYONE_H
#define FOURTYONE_H

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <chrono> // added for play time calculation
#include <ctime>
using namespace std;



struct Card {
    string face; // "A", "2"-"10", "J", "Q", "K"
    string suit; // "H", "D", "S", "C"
};

class Game {
public:
    void createDeck();
    void deal(vector<Card> &hand, vector<Card> &deck, int numCards);
    int getCardValue(Card c);
    int getHandValue(const vector<Card> &hand);
    void printHand(const vector<Card> &hand);
    void printScore(const vector<Card> &hand);
    void takeCard(vector<Card> &hand, vector<Card> &deck);
    bool gameOver(vector<vector<Card> > &hands, vector<Card> &deck);
    int getWinner(vector<vector<Card> > &hands);
    int play();
    int run();

private:
    vector<Card> deck;
};

#endif