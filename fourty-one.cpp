#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

struct Card {
  string face; // "A", "2"-"10", "J", "Q", "K"
  string suit; // "H", "D", "S", "C"
};

void deal(vector<Card> &hand, vector<Card> &deck, int numCards) {
  random_device rd;  // obtain a random seed from the system
  mt19937 gen(rd()); // seed the generator
  for (int i = 0; i < numCards; i++) {
    uniform_int_distribution<> distrib(0, deck.size() - 1);
    int randIndex = distrib(gen);
    hand.push_back(deck[randIndex]);
    deck[randIndex] = deck.back();
    deck.pop_back();
  }
  sort(hand.begin(), hand.end(), [](Card a, Card b) {
    int aValue =
        a.face == "A"
            ? 14
            : (a.face == "J"
                   ? 11
                   : (a.face == "Q" ? 12
                                    : (a.face == "K" ? 13 : stoi(a.face))));
    int bValue =
        b.face == "A"
            ? 14
            : (b.face == "J"
                   ? 11
                   : (b.face == "Q" ? 12
                                    : (b.face == "K" ? 13 : stoi(b.face))));
    return aValue < bValue;
  });
}

int getCardValue(Card c) {
  if (c.face == "A")
    return 11;
  else if (c.face == "J" || c.face == "Q" || c.face == "K")
    return 10;
  else
    return stoi(c.face);
}

int getHandValue(vector<Card> &hand) {
  int value = 0;
  for (Card &c : hand) {
    value += getCardValue(c);
  }
  return value;
}

void printHand(const vector<Card> &hand) {
  for (const auto &card : hand) {
    cout << card.face << card.suit << " ";
  }
  cout << endl;
}

void takeCard(vector<Card> &hand, vector<Card> &deck) {
  cout << "Your hand: ";
  printHand(hand);

  cout << "New card: ";
  random_device rd;  // obtain a random seed from the system
  mt19937 gen(rd()); // seed the generator
  uniform_int_distribution<> distrib(0, deck.size() - 1);
  int randIndex = distrib(gen);
  Card newCard = deck[randIndex];
  deck[randIndex] = deck.back();
  deck.pop_back();
  printHand(vector<Card>{newCard});

  int discardIdx;
  char removeCard;
  cout << "Do you want to discard this drawn card? (y/n): ";
  cin >> removeCard;
  if (removeCard == 'y') {
    cout << "The card has been removed." << endl;
    cout << "Updated hand: ";
    printHand(hand);
    // Remove the card from the deck as well
    deck.push_back(newCard);
    sort(hand.begin(), hand.end(), [](Card a, Card b) {
      int aValue =
          a.face == "A"
              ? 14
              : (a.face == "J"
                     ? 11
                     : (a.face == "Q" ? 12
                                      : (a.face == "K" ? 13 : stoi(a.face))));
      int bValue =
          b.face == "A"
              ? 14
              : (b.face == "J"
                     ? 11
                     : (b.face == "Q" ? 12
                                      : (b.face == "K" ? 13 : stoi(b.face))));
      return aValue < bValue;
    });
    cout << endl << endl;
    return;
  }

  cout << "Choose a card index to discard (0-3): ";
  cin >> discardIdx;

  Card discardedCard = hand[discardIdx];
  hand[discardIdx] = newCard;
  // Remove the card from the deck as well
  deck.push_back(discardedCard);

  cout << "Discarded card: ";
  printHand(vector<Card>{discardedCard});

  sort(hand.begin(), hand.end(), [](Card a, Card b) {
    int aValue =
        a.face == "A"
            ? 14
            : (a.face == "J"
                   ? 11
                   : (a.face == "Q" ? 12
                                    : (a.face == "K" ? 13 : stoi(a.face))));
    int bValue =
        b.face == "A"
            ? 14
            : (b.face == "J"
                   ? 11
                   : (b.face == "Q" ? 12
                                    : (b.face == "K" ? 13 : stoi(b.face))));
    return aValue < bValue;
  });

  cout << "Updated hand: ";
  printHand(hand);

  cout << endl << endl;
}