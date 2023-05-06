#include "switchCard.h"

using namespace std;

// Constructor initializes the game with the given number of players and cards per hand
Switch::Switch(int numPlayers, int numCards)
    : numPlayers(numPlayers), numCards(numCards), deck(createDeck()) {
    shuffleDeck();
}

// Main game loop
void Switch::play() {
    deck = createDeck();
    shuffleDeck();

    dealCards();

    // Iterating through each player's turn
    for (int player = 0; player < numPlayers; ++player) {
        cout << "Player " << player + 1 << "'s turn:" << endl;
        cout << "Your current hand: " << endl;
        printHand(hands[player]);

        int numCardsToSwap;
        cout << "How many cards would you like to swap? (0-" << numCards << "): ";
        cin >> numCardsToSwap;

        // Swapping the cards as per the player's input
        for (int i = 0; i < numCardsToSwap; ++i) {
            int cardIndex;
            cout << "Enter the line of the card to swap (1-" << numCards << "): ";
            cin >> cardIndex;

            swapCards(hands[player], cardIndex - 1);
        }

        cout << "Your new hand: " << endl;
        printHand(hands[player]);
        cout << "----------------------------------" << endl;
    }

    // Scoring and determining the winner
    int player1Score = scoreHand(hands[0]);
    int player2Score = scoreHand(hands[1]);

    cout << "Player 1's score: " << player1Score << endl;
    cout << "Player 2's score: " << player2Score << endl;

    if (player1Score > player2Score) {
        cout << "Player 1 wins!" << endl;
    } else if (player1Score < player2Score) {
        cout << "Player 2 wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}

// Creates a standard deck of cards
vector<Switch::Card> Switch::createDeck() {
    vector<string> faces = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    vector<Card> deck;
    for (const string& suit : suits) {
        for (const string& face : faces) {
            deck.push_back({face, suit});
        }
    }

    return deck;
}

// Shuffles the deck using a random number generator
void Switch::shuffleDeck() {
    std::mt19937 rng;
    rng.seed(std::time(0)); 
    std::shuffle(deck.begin(), deck.end(), rng);  
}

// Deals the initial cards to each player
void Switch::dealCards() {
    hands = vector<vector<Card>>(numPlayers, vector<Card>(numCards));
    for (int player = 0; player < numPlayers; ++player) {
        for (int card = 0; card < numCards; ++card) {
            hands[player][card] = deck.back();
            deck.pop_back();
        }
    }
}

// Prints the cards in a player's hand
void Switch::printHand(const vector<Card>& hand) {
    for (const Card& card : hand) {
        cout << card.face << " of " << card.suit << endl;
    }
}

// Returns the numerical value of a card
int Switch::getCardValue(const Card& card) {
    if (card.face == "A") {
        return 11;
    } else if (card.face == "K" || card.face == "Q" || card.face == "J") {
        return 10;
    } else {
        return stoi(card.face);
    }
}

// Swaps a card in a player's hand with the top card from the deck
void Switch::swapCards(vector<Card>& hand, int cardIndex) {
    hand[cardIndex] = deck.back();
    deck.pop_back();
}

// Calculates the total score of a hand
int Switch::scoreHand(const vector<Card>& hand) {
    int score = 0;
    for (const Card& card : hand) {
        score += getCardValue(card);
    }
    return score;
}

// Main function to start the game
int game2() {
    const int numPlayers = 2;
    const int numCards = 5;

    Switch game(numPlayers, numCards);
    game.play();

    return 0;
}
