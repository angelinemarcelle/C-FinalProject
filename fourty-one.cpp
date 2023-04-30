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

vector<Card> createDeck();
void shuffleDeck(vector<Card>& deck);
vector<vector<Card>> dealCards(vector<Card>& deck, int numPlayers, int numCards);
void playTurn(vector<Card>& hand, vector<Card>& deck);
bool isGameOver(const vector<vector<Card>>& hands, const vector<Card>& deck);
int getWinner(const vector<vector<Card>>& hands);
int getCardValue(const Card& c);
int getHandValue(const vector<Card>& hand);
void printHand(const vector<Card>& hand);

int main() {
        srand(time(nullptr));

        int numPlayers;
        do {
            cout << "How many players? (4-6): ";
            cin >> numPlayers;
            if (numPlayers < 4 || numPlayers > 6) {
                cout << "Invalid number of players! Please input a number between 4-6." << endl;
            }
        } while (numPlayers < 4 || numPlayers > 6);

        vector<Card> deck = createDeck();
        shuffleDeck(deck);

        vector<vector<Card>> hands = dealCards(deck, numPlayers, 4);

        int currentPlayer = 0;
        int turnsPlayed = 0;
        while (!isGameOver(hands, deck) || turnsPlayed < numPlayers) {
            cout << "Player " << currentPlayer + 1 << "'s turn:" << endl;
            playTurn(hands[currentPlayer], deck);
            currentPlayer = (currentPlayer + 1) % numPlayers;
            turnsPlayed++;
        }

        int winner = getWinner(hands);
        cout << "Player " << winner + 1 << " wins!" << endl;
        cout << "Try next game!" << endl;

        return 0;
}

vector<Card> createDeck() {
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
    return deck;
}

void shuffleDeck(vector<Card>& deck) {
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}

vector<vector<Card>> dealCards(vector<Card>& deck, int numPlayers, int numCards) {
    vector<vector<Card>> hands(numPlayers);
    for (int player = 0; player < numPlayers; ++player) {
        for (int card = 0; card < numCards; ++card) {
            hands[player].push_back(deck.back());
            deck.pop_back();
        }
    }
    return hands;
}

bool isGameOver(const vector<vector<Card>>& hands, const vector<Card>& deck) {
    for (const auto& hand : hands) {
        if (getHandValue(hand) >= 21) {
            return true;
        }
    }
    return deck.empty();
}

int getWinner(const vector<vector<Card>>& hands) {
    int winner = 0;
    int highestScore = 0;
    for (int i = 0; i < hands.size(); ++i) {
        int currentScore = getHandValue(hands[i]);
        if (currentScore > highestScore && currentScore <= 21) {
            highestScore = currentScore;
            winner = i;
        }
    }
    return winner;
}

int getCardValue(const Card& c) {
    if (c.face == "A") return 11;
    if (c.face == "K") return 10;
    if (c.face == "Q") return 10;
    if (c.face == "J") return 10;
    return stoi(c.face);
}

int getHandValue(const vector<Card>& hand) {
    int value = 0;
    int aceCount = 0;
    for (const Card& c : hand) {
        if (c.face == "A") {
            aceCount++;
        }
        value += getCardValue(c);
    }

    while (value > 21 && aceCount > 0) {
        value -= 10;
        aceCount--;
    }

    return value;
}

void printHand(const vector<Card>& hand) {
    for (const Card& c : hand) {
        cout << c.face << c.suit << " ";
    }
    cout << endl;
}

void playTurn(vector<Card>& hand, vector<Card>& deck) {
    char choice;
    do {
        cout << "Your current hand: ";
        printHand(hand);
        cout << "Your current score: " << getHandValue(hand) << endl;
        cout << "Do you want to (h)it or (s)tand? ";
        cin >> choice;
        if (choice == 'h' || choice == 'H') {
            hand.push_back(deck.back());
            deck.pop_back();
        } else if (choice != 's' && choice != 'S') {
            cout << "Invalid choice! Please input 'h' or 's'." << endl;
        }
    } while ((choice != 's' && choice != 'S') && !isGameOver({hand}, deck));
}
