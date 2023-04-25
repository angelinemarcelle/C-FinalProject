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
    int aValue;
      if (a.face == "A") {
          aValue = 14;
      } else if (a.face == "J") {
          aValue = 11;
      } else if (a.face == "Q") {
          aValue = 12;
      } else if (a.face == "K") {
          aValue = 13;
      } else {
          aValue = stoi(a.face);
      }

    int bValue;
      if (b.face == "A") {
          bValue = 14;
      } else if (b.face == "J") {
          bValue = 11;
      } else if (b.face == "Q") {
          bValue = 12;
      } else if (b.face == "K") {
          bValue = 13;
      } else {
          bValue = stoi(b.face);
      }
    return aValue < bValue;
  });

  cout << "Updated hand: ";
  printHand(hand);

  cout << endl << endl;
}

bool gameOver(vector<vector<Card>> &hands, vector<Card> &deck) {
  for (auto hand : hands) {
    if (getHandValue(hand) == 41)
      return true;
  }
  return deck.empty();
}

int getWinner(vector<vector<Card>> &hands) {
  int winnerIdx = -1;
  int highest = 0;
  for (int i = 0; i < hands.size(); i++) {
    int score = getHandValue(hands[i]);
    if (score > highest && score <= 41) {
      highest = score;
      winnerIdx = i;
    }
  }
  return winnerIdx;
}

int main() {
  srand(time(nullptr));

  int numPlayers;
  do {
    cout << "How many players? (4-6): ";
    cin >> numPlayers;
    if (numPlayers < 4 || numPlayers > 6) {
      cout << "Invalid number of players! Please input a number between 4-6."
           << endl;
    }
  } while (numPlayers < 4 || numPlayers > 6);

  vector<Card> deck;
  for (int s = 0; s < 4; s++) {
    for (int v = 2; v <= 14; v++) {
      Card c;
      if (v == 11)
        c.face = "J";
      else if (v == 12)
        c.face = "Q";
      else if (v == 13)
        c.face = "K";
      else if (v == 14)
        c.face = "A";
      else
        c.face = to_string(v);
      if (s == 0)
        c.suit = "H";
      else if (s == 1)
        c.suit = "D";
      else if (s == 2)
        c.suit = "S";
      else
        c.suit = "C";
      deck.push_back(c);
    }
  }

  vector<vector<Card>> hands(numPlayers);
  for (auto &hand : hands) {
    deal(hand, deck, 4);
  }

  int currentPlayer = 0;
  while (!gameOver(hands, deck)) {
    cout << "Player " << currentPlayer + 1 << "'s turn:" << endl;
    takeCard(hands[currentPlayer], deck);
    currentPlayer = (currentPlayer + 1) % numPlayers;
  }
  int winner = getWinner(hands);
  cout << "Player " << winner + 1 << " wins!" << endl;
  cout << "Try next game!" << endl;
  return 0;
}
