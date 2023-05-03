#include "fourtyOne.h"


void Game::createDeck() {
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
                c.suit = "♥";
            else if (s == 1)
                c.suit = "♦";
            else if (s == 2)
                c.suit = "♠";
            else
                c.suit = "♣";
            deck.push_back(c);
        }
    }
}

void Game::deal(vector<Card> &hand, vector<Card> &deck, int numCards) {
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

int Game::getCardValue(Card c) {
  if (c.face == "A")
    return 11;
  else if (c.face == "J" || c.face == "Q" || c.face == "K")
    return 10;
  else
    return stoi(c.face);
}

int Game::getHandValue(const vector<Card> &hand) {
  int value = 0;
  for (const Card &c : hand) {
      value += getCardValue(c);
  }
  return value;
}

void Game::printHand(const vector<Card> &hand) {
  for (const auto &card : hand) {
    cout << card.face << card.suit << " ";
   
  }
  cout << endl;
}

void Game::printScore(const vector<Card> &hand) {
    int handValue = getHandValue(hand);
    cout << "Current score: " << handValue << endl;
}

void Game::takeCard(vector<Card> &hand, vector<Card> &deck) {
  cout << "Your hand: ";
  printHand(hand);
  printScore(hand);
  cout << "----------------------------------------------------" << endl;
  cout << "New card: ";
  random_device rd;  // obtain a random seed from the system
  mt19937 gen(rd()); // seed the generator
  uniform_int_distribution<> distrib(0, deck.size() - 1);
  int randIndex = distrib(gen);
  Card newCard = deck[randIndex];
  deck[randIndex] = deck.back();
  deck.pop_back();
  printHand(vector<Card>{newCard});
  cout << "----------------------------------------------------" << endl;
  int discardIdx;
  char removeCard;
  cout << "Do you want to discard this drawn card? (y/n): ";
  cin >> removeCard;
  if (removeCard == 'y') {
    cout << "The card has been removed." << endl;
    cout << "Updated hand: ";
    printHand(hand);
    printScore(hand);
    char out;
    cout << "Enter 'e' to change player's turn!" << endl;
    cin >> out;
    if (out == 'e'){
      system("clear");
    }
    
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
    return;
  }

  cout << "Choose a card index to discard (1-4) ";
  cin >> discardIdx;
  Card discardedCard = hand[discardIdx-1];
  hand[discardIdx-1] = newCard;
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
  printScore(hand);
  char out;
  cout << "Enter 'e' to change player's turn!" << endl;
  cin >> out;
  if (out == 'e'){
    system("clear");
  }
}

bool Game::gameOver(vector<vector<Card>> &hands, vector<Card> &deck) {
  for (auto hand : hands) {
    if (getHandValue(hand) == 41)
      return true;
  }
  return deck.empty();
}

int Game::getWinner(vector<vector<Card>> &hands) {
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

int Game::play() {
    const int numPlayers = 4;
    char reaction;
    createDeck();
    vector<vector<Card>> hands(numPlayers);
    for (auto &hand : hands) {
        deal(hand, deck, 4);
    }

  int currentPlayer = 0;
  while (!gameOver(hands, deck)) {
    cout << "Player " << currentPlayer + 1 << "'s turn:" << endl;
    cout << "----------------------------------------------------" << endl;
    takeCard(hands[currentPlayer], deck);
    currentPlayer = (currentPlayer + 1) % numPlayers;
  }
  int winner = getWinner(hands);


  return winner;
}

int Game::run(){
  Game game;
  while (true) {
      cout << "Welcome to the Exciting 4-Player Card Game!, ready (y/n)? ";
      char reaction;
      cin >> reaction;
      if (reaction != 'y') {
          break;
        }
      else {
        game.play();
      }
      return 0;
    }
  return 0;
}


int game3() {
    srand(time(nullptr));

    Game game;
    game.run();
    int winner = game.play();
    return winner;
}

