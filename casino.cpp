#include <iostream>
#include <string>
using namespace std;

int casino() {
    int num_players;
    int coins = 1000; //num of coins to begin with (shared, one acc only)
    bool valid = false;
    bool quit = false;
    while (coins > 0 && !quit){
        if (coins == 1000){
            cout << "Welcome to the casino! Please tell us number of players (1-4) :\n";
        } else{
            cout << "Welcome again! Please tell us number of players (1-4) for another round\nor (q) to discontinue\nor (c) to check remaining coins:\n";
        }
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
                cout<<"Please tell us number of players (1-4) for another round\nor (q) to discontinue\nor (c) to check remaining coins:\n";
                continue;
            }
            if (userInput.length() >1 || userInput<"1" || userInput>"4"){
                cout << "Cannot be smaller than 1, bigger than 4 or alphabet (1-4)! Please input again :\n";
                continue;
            }
            num_players = stoi(userInput);
            if (num_players >= 1 && num_players <= 4) {
                valid = true;
            } else {
                cout << "Only games with 1-4 players are available. Please input again (1-4) :\n";
            }
        }
        coins--;
    }
}
