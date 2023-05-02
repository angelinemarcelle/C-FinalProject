#include "switchCard.h"


int game2() {
    const int numPlayers = 2;
    const int numCards = 5;

    vector<Cards> deck = createDeck();
    shuffleDeck(deck);

    vector<vector<Cards>> hands = dealCards(deck, numPlayers, numCards);

    for (int player = 0; player < numPlayers; ++player) {
        cout << "Player " << player + 1 << "'s turn:" << endl;
        cout << "Your current hand: " << endl;
        printHand(hands[player]);

        int numCardsToSwap;
        cout << "How many cards would you like to swap? (0-" << numCards << "): ";
        cin >> numCardsToSwap;

        for (int i = 0; i < numCardsToSwap; ++i) {
            int cardIndex;
            cout << "Enter the index of the card to swap (1-" << numCards << "): ";
            cin >> cardIndex;

            hands[player][cardIndex - 1] = deck.back();
            deck.pop_back();
        }

        cout << "Your new hand: " << endl;
        printHand(hands[player]);
        cout << "----------------------------------" << endl;
    }

    int player1Score = scoreHand(hands[0]);
    int player2Score = scoreHand(hands[1]);

    cout << "Player 1's score: " << player1Score << endl;
    cout << "Player 2's score: " << player2Score << endl;

    if (player1Score > player2Score) {
        return 1;
    } else if (player1Score < player2Score) {
        return 2;
    } else {
        return 0;
    }
}


void swapCards(vector<Cards>& hand, vector<Cards>& deck, int cardIndex) {
    hand[cardIndex] = deck.back();
    deck.pop_back();
}

int scoreHand(const vector<Cards>& hand) {
    int score = 0;
    for (const Cards& card : hand) {
        score += getCardValue(card);
    }
    return score;
}

int getCardValue(const Cards& card) {
    if (card.face == "A") {
        return 11;
    } else if (card.face == "K" || card.face== "Q" || card.face == "J") {
        return 10;
    } else {
        return stoi(card.face);
    }
}

vector<Cards> createDeck() {
    vector<string> faces = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    vector<Cards> deck;
    for (const string& suit : suits) {
        for (const string& face : faces) {
            deck.push_back({face, suit});
        }
    }

    return deck;
}

void shuffleDeck(vector<Cards>& deck) {
    random_shuffle(deck.begin(), deck.end());
}

vector<vector<Cards>> dealCards(vector<Cards>& deck, int numPlayers, int numCards) {
    vector<vector<Cards>> hands(numPlayers, vector<Cards>(numCards));
    for (int player = 0; player < numPlayers; ++player) {
        for (int card = 0; card < numCards; ++card) {
            hands[player][card] = deck.back();
            deck.pop_back();
        }
    }

    return hands;
}

void printHand(const vector<Cards>& hand) {
    for (const Cards& card : hand) {
        cout << card.face << " of " << card.suit << endl;
    }
}
