#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

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

Switch::Switch(int numPlayers, int numCards)
    : numPlayers(numPlayers), numCards(numCards), deck(createDeck()) {
    shuffleDeck();
}

void Switch::play() {
    deck = createDeck();
    shuffleDeck();

    dealCards();

    for (int player = 0; player < numPlayers; ++player) {
        cout << "Player " << player + 1 << "'s turn:" << endl;
        cout << "Your current hand: " << endl;
        printHand(hands[player]);

        int numCardsToSwap;
        cout << "How many cards would you like to swap? (0-" << numCards << "): ";
        cin >> numCardsToSwap;

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

void Switch::shuffleDeck() {
    random_shuffle(deck.begin(), deck.end());
}

void Switch::dealCards() {
    hands = vector<vector<Card>>(numPlayers, vector<Card>(numCards));
    for (int player = 0; player < numPlayers; ++player) {
        for (int card = 0; card < numCards; ++card) {
            hands[player][card] = deck.back();
            deck.pop_back();
        }
    }
}

void Switch::printHand(const vector<Card>& hand) {
    for (const Card& card : hand) {
        cout << card.face << " of " << card.suit << endl;
    }
}

int Switch::getCardValue(const Card& card) {
    if (card.face == "A") {
        return 11;
    } else if (card.face == "K" || card.face == "Q" || card.face == "J") {
        return 10;
    } else {
        return stoi(card.face);
    }
}

void Switch::swapCards(vector<Card>& hand, int cardIndex) {
    hand[cardIndex] = deck.back();
    deck.pop_back();
}

int Switch::scoreHand(const vector<Card>& hand) {
    int score = 0;
    for (const Card& card : hand) {
        score += getCardValue(card);
    }
    return score;
}

int main() {
    const int numPlayers = 2;
    const int numCards = 5;

    Switch game(numPlayers, numCards);
    game.play();

    return 0;
}
