#include "fourtyOne.h"

//function to generate a full deck of 52 cards
void Game::createDeck() {
    for (int s = 0; s < 4; s++) { //loop through the 4 suits
        for (int v = 2; v <= 14; v++) { //loop through the card numbers
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
                c.face = to_string(v); //store the card number
            if (s == 0)
                c.suit = "♥";
            else if (s == 1)
                c.suit = "♦";
            else if (s == 2)
                c.suit = "♠";
            else
                c.suit = "♣";
            deck.push_back(c); //add the card to the deck
        }
    }
}

//function to deal card from deck to the player's hand
void Game::deal(vector<Card> &hand, vector<Card> &deck, int numCards) {
  random_device rd;  // obtain a random seed from the system
  mt19937 gen(rd()); // seed the generator
  for (int i = 0; i < numCards; i++) {
    uniform_int_distribution<> distrib(0, deck.size() - 1);
    int randIndex = distrib(gen);
    hand.push_back(deck[randIndex]); //give card to player
    deck[randIndex] = deck.back(); //replace the card given with the last card
    deck.pop_back(); //remove last card
  }
  //sort player's card based on the card's number
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

//function to declare the value of the card
int Game::getCardValue(Card c) {
  if (c.face == "A")
    return 11;
  else if (c.face == "J" || c.face == "Q" || c.face == "K")
    return 10;
  else
    return stoi(c.face);
}

//function to calculates value of card in the player's hand
int Game::getHandValue(const vector<Card> &hand) {
  int value = 0;
  for (const Card &c : hand) {
      value += getCardValue(c);
  }
  return value;
}

//function to print the card in player's hand
void Game::printHand(const vector<Card> &hand) {
  for (const auto &card : hand) {
    cout << card.face << card.suit << " ";
   
  }
  cout << endl;
}

//function to print the total score that been counted in getHandValue()
void Game::printScore(const vector<Card> &hand) {
    int handValue = getHandValue(hand);
    cout << "Current score: " << handValue << endl;
}

//function to update the screen with every changes
void Game::takeCard(vector<Card> &hand, vector<Card> &deck) {
  cout << "Your hand: ";
  printHand(hand); //print hand
  printScore(hand); //print value in hand
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
  cin >> removeCard; //input if player want to remove any card or not
  if (removeCard == 'e'){ //if the player wants to exit the game
    ::exit(0);
  }
  else if (removeCard == 'y') { //give player card
    cout << "The card has been removed." << endl;
    cout << "Updated hand: ";
    printHand(hand);
    printScore(hand);
    char out;
    cout << "Enter 'e' to change player's turn!" << endl;
    cin >> out;
    if (out == 'e'){ //input to clear the screen
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
  cin >> discardIdx; //input of the card index to remove
  Card discardedCard = hand[discardIdx-1];
  hand[discardIdx-1] = newCard;
  // Remove the card from the deck as well
  deck.push_back(discardedCard);

  cout << "Discarded card: ";
  printHand(vector<Card>{discardedCard}); //print the updated hand

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

//function to check if the game is over
bool Game::gameOver(vector<vector<Card>> &hands, vector<Card> &deck) {
  for (auto hand : hands) {
    if (getHandValue(hand) == 41) //winning condition
      return true;
  }
  return deck.empty(); //deck is empty = game over
}

//function to get the winner
int Game::getWinner(vector<vector<Card>> &hands) {
  int winnerIdx = -1;
  int highest = 0;
  for (int i = 0; i < hands.size(); i++) {
    int score = getHandValue(hands[i]);
    if (score > highest && score <= 41) { //winning condition
      highest = score;
      winnerIdx = i; //set the winner index
    }
  }
  return winnerIdx; //return the index of the winner
}

//function to play the whole game
int Game::play() {
    const int numPlayers = 4;
    char reaction;
    createDeck(); //create a whole deck
    vector<vector<Card>> hands(numPlayers); 
    for (auto &hand : hands) {
        deal(hand, deck, 4); //give player a total of 4 cards
    }

  int currentPlayer = 0;
  while (!gameOver(hands, deck)) { //while the game is not over
    cout << "Player " << currentPlayer + 1 << "'s turn:" << endl;
    cout << "----------------------------------------------------" << endl;
    takeCard(hands[currentPlayer], deck);
    currentPlayer = (currentPlayer + 1) % numPlayers;
  }
  int winner = getWinner(hands);


  return winner;
}


//function for the opening, if the player want to play this game or not
int Game::run(){
  Game game;
  while (true) {
      
      cout << "Welcome to the Exciting 4-Player Card Game!, ready (y/n)? ";
      char reaction;
      cin >> reaction;
      if (reaction == 'n') {
        ::exit(0);
      }
      else if (reaction =='y'){
        game.play();
      }
      else {
        ::exit(0);
      }
      
      return 0;
    }
  return 0;
}

//the main function to run the whole code's program
int game3() {
    srand(time(nullptr));

    Game game;
    game.run();
    int winner = game.play();
    return winner;
}

