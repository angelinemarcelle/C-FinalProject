#include <iostream>
#include <string>
using namespace std;

// Include the game functions here
void playCardMatchingGame();
void playMemoryGame();
void playSimpleCardGame();

int casino() {
    int num_players;
    int coins = 1000; //num of coins to begin with (shared, one account only)
    bool valid = false;
    bool quit = false;
    while (coins > 0 && !quit){
        if (coins == 1000){
            cout << "Welcome to the casino! Please choose a game to play:\n";
        } else{
            cout << "Welcome again! Please choose a game to play for another round\nor (q) to discontinue\nor (c) to check remaining coins:\n";
        }
        cout << "1. Card Matching Game\n";
        cout << "2. Memory Game\n";
        cout << "3. Simple Card Game\n";
        valid = false;
        string userInput;
        while(!valid){
            cin >> userInput;
            if (userInput == "q" || userInput == "Q" || userInput == "quit" || userInput == "Quit"){
                cout<<"Thanks for playing. Your remaining coins: "<<coins<<endl;
                quit = true;
                break;
            }
            if (userInput == "c" || userInput == "C" || userInput == "check" || userInput == "Check"){
                cout<<"Your remaining coins: "<<coins<<endl;
                cout<<"Please choose a game to play for another round\nor (q) to discontinue\nor (c) to check remaining coins:\n";
                continue;
            }
            if (userInput.length() >1 || userInput<"1" || userInput>"3"){
                cout << "Invalid input! Please choose a game (1-3):\n";
                continue;
            }
            int game_choice = stoi(userInput);
            if (game_choice >= 1 && game_choice <= 3) {
                valid = true;
            } else {
                cout << "Invalid input! Please choose a game (1-3):\n";
            }
        }
        coins--; // Deduct coins for playing a game

        switch (stoi(userInput)) {
            case 1:
                playCardMatchingGame();
                break;
            case 2:
                playMemoryGame();
                break;
            case 3:
                playSimpleCardGame();
                break;
            default:
                break;
        }
    }
}
