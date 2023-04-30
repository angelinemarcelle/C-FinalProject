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
    int money[6] = {200, 200, 200, 200, 200, 200}; // starting money
    int currentPlayer = 0;
    int currentMultiplayer = 0; // player temporary score for multiplayer game
    int currentTwoPlayer = 0;
 
    while (!exit) {
        cout << "-------------------------------- :Welcome to: --------------------------------" << endl;
        cout << "░█████╗░░█████╗░██████╗░██████╗░  ░█████╗░░█████╗░░██████╗██╗███╗░░██╗░█████╗░" << endl;
        cout << "██╔══██╗██╔══██╗██╔══██╗██╔══██╗  ██╔══██╗██╔══██╗██╔════╝██║████╗░██║██╔══██╗" << endl;
        cout << "██║░░╚═╝███████║██████╔╝██║░░██║  ██║░░╚═╝███████║╚█████╗░██║██╔██╗██║██║░░██║" << endl;
        cout << "██║░░██╗██╔══██║██╔══██╗██║░░██║  ██║░░██╗██╔══██║░╚═══██╗██║██║╚████║██║░░██║" << endl;
        cout << "╚█████╔╝██║░░██║██║░░██║██████╔╝  ╚█████╔╝██║░░██║██████╔╝██║██║░╚███║╚█████╔╝" << endl;
        cout << "░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░  ░╚════╝░╚═╝░░╚═╝╚═════╝░╚═╝╚═╝░░╚══╝░╚════╝░" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "Welcome to Card Casino!" << endl;
        cout << "1. Play single player (Card Match) " << endl;
        cout << "2. Play multiplayer (41): " << endl;
        cout << "3. Play two player (Switch Card)" << endl;
        cout << "4. View leaderboard" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5) : ";
        cin >> choice;
        switch (choice) {
            case 1:
                // start game 1
                cout << "Which player is playing? (1-6): ";
                cin >> currentPlayer;
                currentPlayer -= 1; // Adjusting the index to be 0-based
                money[currentPlayer] += playCardMatchingGame(); // add the score to current player playing
                break;
            case 2:
                // start game 2 TO BE IMPLEMENTED
                cout << "Which players are playing? (Enter the player numbers, 4-6 players allowed, example: 1234 or 23456): ";
                cin >> currentMultiplayer;
                currentPlayer -= 1; // Adjusting the index to be 0-based
                money[currentPlayer] += playMemoryGame(); // add the score to current player playing
                break;
            case 3:
                // start game 3 // TO BE IMPLEMENTED
                cout << "Which players are playing? (Enter the player numbers, 2 players allowed ): ";
                cin >> currentTwoPlayer; // to be implemented
                currentPlayer -= 1; // Adjusting the index to be 0-based
                money[currentPlayer] += playSimpleCardGame(); // add the score to current player playing
                break;
            case 4:
                // view leaderboard
                cout << "Leaderboard:" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << "Player " << i + 1 << ": " << "$" << money[i] << endl;
                }
                break;
            case 5:
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please choose a number between 1-5." << endl;
                break;
        }
    }
}
