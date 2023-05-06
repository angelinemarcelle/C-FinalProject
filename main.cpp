// Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "cardMatch.h"
#include "switchCard.h"
#include "fourtyOne.h"

using namespace std;

// Include the game functions here
int game1(); // 1 player game
int game2(); // 2 player game
int game3(); // 4 player game

// Players' database
struct Player {
  string name; // player's name
  int money; // player's score
};

// Declare ifstream ofstream
ifstream infile;
ofstream outfile;

// Save ingame data
void save(Player* players) {
    outfile.open("gameData.txt");
    if (outfile.is_open()) {
        for (int i = 0; i < 4; i++) {
            outfile << players[i].name << " " << players[i].money << endl;
        }
        outfile.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
}

// Clear ingame data
void clear() {
    ofstream file("gameData.txt", ofstream::out | ofstream::trunc);
    file.close();
}

// Load game data
void load(Player* players) {
    ifstream infile("gameData.txt");
    if (infile.is_open()) {
        for (int i = 0; i < 4; i++) {
            infile >> players[i].name >> players[i].money;
        }
        infile.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    int choice; // player's choise
    // title screen
    cout << "------------------------------- :Welcome to: ---------------------------------" << endl;
    cout << "░█████╗░░█████╗░██████╗░██████╗░  ░█████╗░░█████╗░░██████╗██╗███╗░░██╗░█████╗░" << endl;
    cout << "██╔══██╗██╔══██╗██╔══██╗██╔══██╗  ██╔══██╗██╔══██╗██╔════╝██║████╗░██║██╔══██╗" << endl;
    cout << "██║░░╚═╝███████║██████╔╝██║░░██║  ██║░░╚═╝███████║╚█████╗░██║██╔██╗██║██║░░██║" << endl;
    cout << "██║░░██╗██╔══██║██╔══██╗██║░░██║  ██║░░██╗██╔══██║░╚═══██╗██║██║╚████║██║░░██║" << endl;
    cout << "╚█████╔╝██║░░██║██║░░██║██████╔╝  ╚█████╔╝██║░░██║██████╔╝██║██║░╚███║╚█████╔╝" << endl;
    cout << "░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░  ░╚════╝░╚═╝░░╚═╝╚═════╝░╚═╝╚═╝░░╚══╝░╚════╝░" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Press enter to continue!" << endl;
    cin.ignore();
    // Register player
    Player players[4];

    // Read in the names of the 4 players
    if (infile.fail()) {
        cout << "Unable to open file." << endl;
        exit(0);
    }
    else{
        infile.open("gameData.txt");
        if (infile.peek() == ifstream::traits_type::eof()) {
            // File is empty register user data first
            cout << "No previous game data found. Please enter the player data first:" << endl;
            for (int i = 0; i < 4; i++) {
                cout << "Enter the name of player " << i+1 << ": ";
                cin >> players[i].name;
                //players[i].name = &name;
                //int* money = new int(1000);
                players[i].money = 1000;
            }
            // Save player data to file
            save(players);
        }
        else {
            // Read player data from file
            load(players);
        }
    }

    // Print out the names of the 4 players
    cout << endl << endl;
    cout << "All players' starting money: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << i+1 << ". " << players[i].name << ": " << "$" << players[i].money << endl;
    }
    cout << endl << endl;
    cout << "Press enter to let the game begin!" << endl;
    cin.ignore();
    system("clear");
  
    while (true) {
        // Main menu
        cout << "1. Play single player (Card Match) " << endl;
        cout << "2. Play two player (Switch Card)" << endl;
        cout << "3. Play multiplayer (41): " << endl;
        cout << "4. View all players' money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5) : ";
        cin >> choice;
        cout << endl << endl;
        system("clear");
        switch (choice) {
        case 1:
            // Start game 1
            int player1;
            cout << "Who is playing? (Enter player number): ";
            cin >> player1;
            player1 -= 1; // Adjusting the index to be 0-based     
            // Ask the player to wager their score
            int wager;
            cout << "Enter your wager: ";
            cin >> wager;
            // Check if the player has enough money to make the wager
            if (players[player1].money < wager) {
                cout << "Sorry, you don't have enough money to make that wager." << endl;
            } else {
                // Subtract the wager from the player's score
                players[player1].money -= wager;
                save(players);
                // Run the game 
                int result = game1();
                // Double the score if the player wins, or set it to 0 if they lose
                if (result == 3){
                    players[player1].money += 3 * wager;
                    save(players);
                    cout << "Congratulations! You won " <<"$ " << 3 * wager << endl;
                    cout << endl << endl;
                } 
                else if (result == 2){
                    players[player1].money += 2 * wager;
                    save(players);
                    cout << "Congratulations! You won " <<"$ " << 1 * wager << endl;
                    cout << endl << endl;
                }
                else {
                    cout << "Sorry, you lost your wager." << endl;
                    cout << endl << endl;
                }
              }
              cout << endl << endl;
            break;
            
        case 2:
            // Start game 2
            int player2;
            cout << "Who are playing? (Enter player numbers): "; 
            cin >> player1 >> player2;
            player1 -= 1; // Adjusting the index to be 0-based
            player2 -= 1; // Adjusting the index to be 0-based
            if ( player1 > 3 || player2 > 3 || player1 < 0 || player2 < 0 ) {
                cout << "Sorry, you have entered an invalid player number." << endl;
                system("clear");
                continue;
            }
            
            // Ask the players to wager their scores
            cout << "Enter the wager for both players: ";
            cin >> wager;
            
            // Check if the players have enough money to make the wager
            if (players[player1].money < wager || players[player2].money < wager) {
                cout << "Sorry, one or both players don't have enough money to make that wager." << endl;
                cout << endl << endl;

            } else {
                // Subtract the wager from the players' scores
                players[player1].money -= wager;
                players[player2].money -= wager;
                save(players);
                int resultg2 = game2();
                // Determine the winner of the game
                if (resultg2 == 1) { // player 1 wins
                    players[player1].money += 2 * wager;
                    cout << players[player1].name << " wins " << "$" << 2 * wager << endl;
                    save(players);
                } else if (resultg2 == 2){ 
                    players[player2].money += 2 * wager;
                    cout << players[player2].name << " wins " << "$" << 2 * wager << endl;
                    save(players);
                    continue;
                }
              else{ // Tie, return initial money
                    players[player1].money +=  wager;
                    players[player2].money +=  wager;
                    
                    save(players);
                    continue;
              }
            }
            cout << endl << endl;
            break;

        case 3: {
        // Start game 3
            int numPlayers = 4;
            cout << "Enter the wager for all players: ";
            cin >> wager;
        
            // Check if all players have enough money to make the wager
            bool allPlayersHaveEnoughMoney = true;
            for (int i = 0; i < numPlayers; i++) {
                if (players[i].money < wager) {
                    allPlayersHaveEnoughMoney = false;
                }
            }
            
            if (!allPlayersHaveEnoughMoney) {
                cout << "Sorry, one or more players don't have enough money to make that wager." << endl;
                cout << endl << endl;
                system("clear");
                continue;

            } else {
                // Subtract the wager from all players' scores
                for (int i = 0; i < numPlayers; i++) {
                    players[i].money -= wager;
                }
                save(players);
            }
            cout << endl << endl;
          
            // Play the game 
            int winningPlayerIndex = game3();
          
            // Award them all the money wagered
            int totalWinnings = 4 * wager;
            players[winningPlayerIndex].money += totalWinnings;
            cout << players[winningPlayerIndex].name << " wins $" << totalWinnings << " !" << endl;
            save(players);
            break;
        }
                
        case 4:
            // View players' money
            cout << "Players' Money:" << endl;
            for (int i = 0; i < 4; i++) {
                cout << players[i].name << ": " << "$" << players[i].money << endl;
            }
            cout << endl << endl;
            break;
          
        case 5: 
            // Exit game
            while (true){
                cout << "Would you like to save all game prgoress? (y/n)" << endl;
                char yn;
                cin >> yn;
                if (yn == 'y'){
                    save(players);
                    exit(0);
                    break;
                } else if (yn == 'n'){
                    clear();
                    exit(0);
                    break;
                } else {
                    cout << "Invalid input, please choose y or n!" << endl;
                }
            }          
            
        default:
            // Invalid input
            cout << "Invalid choice. Please choose a number between 1-5." << endl;
            cout << endl << endl;
            system("clear");
            break;

        }
    }
    return 0;
}

