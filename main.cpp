#include <iostream>
#include <fstream>
#include "cardmatch.h"
#include <string>

using namespace std;

// Include the game functions here
int playMemoryGame(); // 1 player game
int playCardMatchingGame(); // 2 player game
int playSimpleCardGame(); // 4 player game

// Players' database
struct Player {
  string name; // player's name
  int money; // player's score
};

//Save ingame data
void save(){
    ofstream outfile("gamedata.txt");
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
    char _; // variable for entering
    int choice;
    bool exit = false;
    // title screen
    cout << "-------------------------------- :Welcome to: --------------------------------" << endl;
    cout << "░█████╗░░█████╗░██████╗░██████╗░  ░█████╗░░█████╗░░██████╗██╗███╗░░██╗░█████╗░" << endl;
    cout << "██╔══██╗██╔══██╗██╔══██╗██╔══██╗  ██╔══██╗██╔══██╗██╔════╝██║████╗░██║██╔══██╗" << endl;
    cout << "██║░░╚═╝███████║██████╔╝██║░░██║  ██║░░╚═╝███████║╚█████╗░██║██╔██╗██║██║░░██║" << endl;
    cout << "██║░░██╗██╔══██║██╔══██╗██║░░██║  ██║░░██╗██╔══██║░╚═══██╗██║██║╚████║██║░░██║" << endl;
    cout << "╚█████╔╝██║░░██║██║░░██║██████╔╝  ╚█████╔╝██║░░██║██████╔╝██║██║░╚███║╚█████╔╝" << endl;
    cout << "░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░  ░╚════╝░╚═╝░░╚═╝╚═════╝░╚═╝╚═╝░░╚══╝░╚════╝░" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Press any key to continue!" << endl;
    cin >> _;
    // register player
    Player players[4];
    ifstream infile("gamedata.txt");
    // Read in the names of the 4 players
    if (infile.is_open()) {
        // Check if file is empty
        infile.seekg(0, ios::end);
        if (infile.tellg() == 0) {
            // File is empty register user data first
            cout << "No game data found. Please enter the player data:" << endl;
            for (int i = 0; i < 4; i++) {
                cout << "Enter the name of player " << i+1 << ": ";
                cin >> players[i].name;
                players[i].money = 1000;
            }
            // Save player data to file
            ofstream outfile("gamedata.txt");
            if (outfile.is_open()) {
                for (int i = 0; i < 4; i++) {
                    outfile << players[i].name << " " << players[i].money << endl;
                }
                outfile.close();
            }
            else { // If the file is unable to be opened
                cout << "Unable to open file." << endl;
            }
        }
        else {
            // Read player data from file
            infile.seekg(0, ios::beg);
            for (int i = 0; i < 4; i++) {
                infile >> players[i].name >> players[i].money;
            }
            infile.close();
        }
    }
    else { // If the file is unable to be opened
        cout << "Unable to open file." << endl;
    }

    // Print out the names of the 4 players
    cout << "All players' starting money: ";
    for (int i = 0; i < 4; i++) {
        cout << i+1 << "." <<players[i].name << ": "<<"$1000" << endl;
    }
    cout << "Press enter to let the game begin!" << endl;
    cin >> _;
  
    while (!exit) {
        // main menu
        cout << "1. Play single player (Card Match) " << endl;
        cout << "2. Play two player (Switch Card)" << endl;
        cout << "3. Play multiplayer (41): " << endl;
        cout << "4. View all players' money" << endl;
        cout << "5. Read game rules" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6) : ";
        cin >> choice;

        switch (choice) {
        case 1:
            // start game 1
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
                save();
                // Run the game 
                bool win = playMemoryGame();
                // Double the score if the player wins, or set it to 0 if they lose
                if (win){
                    players[player1].money += 2 * wager;
                    save()
                    cout << "Congratulations! You won " <<"$ " << 2 * wager << endl;
                } else {
                    cout << "Sorry, you lost your wager." << endl;
                }
              }
            break;
            
        case 2:
            // start game 2
            int player1, player2;
            cout << "Who are playing? (Enter player numbers): ";
            cin >> player1 >> player2;
            player1 -= 1; // Adjusting the index to be 0-based
            player2 -= 1; // Adjusting the index to be 0-based
            
            // Ask the players to wager their scores
            int wager;
            cout << "Enter the wager for both players: ";
            cin >> wager;
            
            // Check if the players have enough money to make the wager
            if (players[player1].money < wager || player[player2].money < wager) {
                cout << "Sorry, one or both players don't have enough money to make that wager." << endl;
            } else {
                // Subtract the wager from the players' scores
                players[player1].money -= wager;
                players[player2].money -= wager;
                save();
                // Determine the winner of the game
                if (playCardMatchingGame()) { // player 1 wins
                    players[player1].money += 2 * wager;
                    cout << players[player1].name << " wins " << 2 * wager << " points!" << endl;
                    save();
                } else { // player 2 wins
                    players[player2].money += 2 * wager;
                    cout << players[player2].name << " wins " << 2 * wager << " points!" << endl;
                    save();
                }
            }
            break;

          case 3:
            // start game 3
            int wager;
            int numPlayers = 4;
            cout << "Enter the wager for all players: ";
            cin >> wager;
        
            // Check if all players have enough money to make the wager
            bool allPlayersHaveEnoughMoney = true;
            for (int i = 0; i < numPlayers; i++) {
                if (players[i].money < wager) {
                    allPlayersHaveEnoughMoney = false;
                    break;
                }
            }
            
            if (!allPlayersHaveEnoughMoney) {
                cout << "Sorry, one or more players don't have enough money to make that wager." << endl;
            } else {
                // Subtract the wager from all players' scores
                for (int i = 0; i < numPlayers; i++) {
                    players[i].money -= wager;
                }
                save();
              }
        
                // Play the game 
                int winningPlayerIndex = playSimpleCardGame();
                // Award them all the money wagered
                int totalWinnings = 4 * wager;
                players[winningPlayerIndex].money += totalWinnings;
                cout << players[winningPlayerIndex].name << " wins " << totalWinnings << " points!" << endl;
                save();
                break;
                
          case 4:
                // view players' money
                cout << "Players' Money:" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << players[i].name << ": " << "$" << players[i].money << endl;
                }
                break;
          case 5:
                // view game rules
                int choice;
                bool valid_choice = false;
                while (!valid_choice) {
                    cout << "Which game rule do you want to see?" << endl;
                    cout << "1. Single player (Card Match)\n2. Double player (Switch Card)\n3. Multiplayer (41): (1-3)" << endl;
                    cin >> choice;
                    if (choice == 1) {
                        // view game rules for single player (Card Match)
                        cout << "Welcome to Card Match, a simple single player game of memorization! \nIn this game, you will be challenged to memorize cards within a limited time frame." << endl;
                        cout << endl;
                        cout << "To play, follow these simple steps:" << endl;
                        cout << "\t1. Choose the board size by entering 4 or 6. The bigger the board size, the more cards will be in play." << endl;
                        cout << "\t2. You will be given 5 seconds to memorize the card elements displayed on the board." << endl;
                        cout << "\t3. Enter two numbers that you think are the same." << endl;
                        cout << endl;
                        cout << "If you can successfully complete the game within the allotted time, you will win a prize based on your performance." << endl;
                        cout << "For the 4x4 board, if you finish in under 30 seconds, you will receive double your initial wager. \nIf you finish in over 30 seconds, you will receive your initial wager." << endl;
                        cout << "For the 6x6 board, you can win even more! If you finish in under 1 minute, you will receive three times your initial wager. \nIf you finish in under 2 minutes but over 1 minute, you will receive double your initial wager. \nIf you take over 2 minutes, you will still receive your initial wager." << endl;
                        cout << endl;
                        cout << "Get your mind ready and play to win more money! Good luck and happy playing." << endl;
                        valid_choice = true;
                    } else if (choice == 2) {
                        // view game rules for double player (Switch Card)
                        cout << "Welcome to the Switch Card Dual player game! \nIn this game, two players will compete to get the highest possible value from a combination of 5 cards." << endl;
                        cout << endl;
                        cout << "Here's how to play:" << endl;
                        cout << "\t1. First, each player will be given 5 cards randomly chosen from a deck of 52 cards." << endl;
                        cout << "\t2. Each player will be shown their collection of cards, but keep it hidden from your opponent. You will then have the option to either keep your cards or swap them with random cards generated from the deck." << endl;
                        cout << "\t3. If you choose to swap your cards, you will be given the option to choose how many and which cards to swap (1-5)." << endl;
                        cout << "\t4. After both players have dealt their cards, both hands are revealed to each other. The player with the higher value of cards will win." << endl;
                        cout << endl;
                        cout << "To calculate your score, use the following values:" << endl;
                        cout << "\t - Number cards represent their own numbers." << endl;
                        cout << "\t - Face cards (Jack, Queen, King) represent 10." << endl;
                        cout << "\t - Ace represents 11." << endl;
                        cout << endl;
                        cout << "If you win, you will receive all the wager from the other player. Since it's a double or nothing game, you'll need luck on your side!" << endl;
                        cout << "Good luck and have fun playing!" << endl;
                        valid_choice = true;
                    } else if (choice == 3) {
                        // view game rules for multiplayer (41)
                        cout << "Welcome to the 41 Multiplayer game! \nIn this game, you will be playing alongside 3 other players. The ultimate goal of the game is to get a score of 41 from a combination of 4 cards." << endl;
                        cout << endl;
                        cout << "Here's how to play:" << endl;
                        cout << "\t1. To start the game, press \"y\" and hit enter." << endl;
                        cout << "\t2. Your cards will be displayed on the screen, along with your current score. You will have the option to either keep your current hand of cards or switch one of your cards with a new card to try and get a better score." << endl;
                        cout << "\t3. If you want to switch a card, press \"y\" and then choose the index of the card you want to switch (0-3). If you decide to keep your cards, press \"n\"." << endl;
                        cout << "\t4. All players will take turns until one player gets a score of 41." << endl;
                        cout << endl;
                        cout << "To calculate your score, use the following values:" << endl;
                        cout << "\t - Number cards represent their own numbers." << endl;
                        cout << "\t - Face cards (Jack, Queen, King) represent 10." << endl;
                        cout << "\t - Ace represents 11." << endl;
                        cout << endl;
                        cout << "If you win, you will receive the combined wager from all players. Remember, the winner takes it all, so play and strategize well!" << endl;
                        cout << "Good luck and have fun playing!" << endl;
                        valid_choice = true;
                    } else {
                        cout << "Please input a valid number to view its game rules!" << endl;
                    }
                }
                break;
            case 6:
                exit = true;
                save();
                break;
            default:
                cout << "Invalid choice. Please choose a number between 1-5." << endl;
                break;
    return 0;
    }
  
} 



