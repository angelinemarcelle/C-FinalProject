#include <iostream>
#include "cardmatch.h"
using namespace std;

int main() {
    int choice;
    bool exit = false;
    int scores[4] = {0, 0, 0, 0}; // players score
    int currentPlayer = 0;
    
    while (!exit) {
        cout << "🅲🅰🆁🅳 🅲🅰🆂🅸🅽🅾" << endl;
        cout << "Welcome to Card Casino!" << endl;
        cout << "1. Play single player (Card Match) " << endl;
        cout << "2. Play together (): " << endl;
        cout << "3. View leaderboard" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4) : ";
        cin >> choice;
        switch (choice) {
            case 1:
                // start game 1
                cout << "Which player is playing? (1-4): ";
                cin >> currentPlayer;
                scores[currentPlayer] += playCardMatch() // add the score to current player playing
                break;
            case 2:
                // start game 2
                break;
            case 3:
                    // view leaderboard
              cout << "Leaderboard:" << std::endl;
              for (int i = 0; i < 4; i++) {
                  cout << "Player " << i + 1 << ": " << scores[i] << std::endl;
              }
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
    return 0;
}
