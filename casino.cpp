#include <iostream>
#include "cardmatch.h"
using namespace std;

// Include the game functions here
int playCardMatchingGame();
int playMemoryGame();
int playSimpleCardGame();

void casino() {
    int choice;
    bool exit = false;
    int scores[4] = {0, 0, 0, 0}; // players score
    int currentPlayer = 0;
    
    while (!exit) {
        cout << "🅲🅰🆁🅳 🅲🅰🆂🅸🅽🅾" << endl;
        cout << "Welcome to Card Casino!" << endl;
        cout << "1. Play single player (Card Match) " << endl;
        cout << "2. Play together (Memory Game): " << endl;
        cout << "3. Play Simple Card Game" << endl;
        cout << "4. View leaderboard" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5) : ";
        cin >> choice;
        switch (choice) {
            case 1:
                // start game 1
                cout << "Which player is playing? (1-4): ";
                cin >> currentPlayer;
                currentPlayer -= 1; // Adjusting the index to be 0-based
                scores[currentPlayer] += playCardMatchingGame(); // add the score to current player playing
                break;
            case 2:
                // start game 2
                cout << "Which player is playing? (1-4): ";
                cin >> currentPlayer;
                currentPlayer -= 1; // Adjusting the index to be 0-based
                scores[currentPlayer] += playMemoryGame(); // add the score to current player playing
                break;
            case 3:
                // start game 3
                cout << "Which player is playing? (1-4): ";
                cin >> currentPlayer;
                currentPlayer -= 1; // Adjusting the index to be 0-based
                scores[currentPlayer] += playSimpleCardGame(); // add the score to current player playing
                break;
            case 4:
                // view leaderboard
                cout << "Leaderboard:" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << "Player " << i + 1 << ": " << scores[i] << endl;
                }
                break;
            case 5:
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
