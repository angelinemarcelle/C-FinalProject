#include 'cardmatch.h'
using namespace std;

class Board { // updated class 30th April 2023
public:
    int board_size;
    bool first_turn = true;
    vector<vector<string>> board;
    vector<vector<bool>> revealed;
    int play();
    void print(bool show_all = false);
    vector<vector<string>> createBoard(int board_size);
    int calculateweight();
};

int Board::play() { // moved this from main function to void play() for better organisation
    int matches_found = 0;
    int total_pairs = (board_size * board_size) / 2;
    auto start_time = chrono::steady_clock::now(); // start timing
    bool gameplay = true;

    while (gameplay) { // game loop 
        if (first_turn) {
            print(true);
            first_turn = false;
            cout << "Memorise the picture of the board for 5 seconds" << endl;
            cout << "Do not press any key while this screen is on!" << endl;
            this_thread::sleep_for(chrono::seconds(5));
            system("clear");
            cout << "From now on, your play time will be recorded!" << endl;
            print();
        } else {
            print();
        }
        
        int cell1, cell2; // input variables
        cout << "Choose two cells to reveal (1-" << board_size * board_size << "): ";
        cin >> cell1 >> cell2;

        if (cin.fail()) { // Check if the user has chosen the same cell twice
            cout << "You have inputted an invalid input\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int row1 = (cell1 - 1) / board_size; // Convert cell numbers to board indices
        int col1 = (cell1 - 1) % board_size;
        int row2 = (cell2 - 1) / board_size;
        int col2 = (cell2 - 1) % board_size;

        if (cell1 == cell2) {
            cout << "You cannot choose the same cell twice. Try again.\n";
            continue;
        } else if (revealed[row1][col1] || revealed[row2][col2]) {
            cout << "You have already chosen that cell previously\n";
            continue;
        }

        revealed[row1][col1] = true; // Reveal the cells
        revealed[row2][col2] = true;

        if (board[row1][col1] != board[row2][col2]) { // Check if the cells match
            system("clear"); // added system("clear") so that the player has a clear screen
			print(false);
			cout << "No match. Try again.\n" << endl;
			revealed[row1][col1] = false;
			revealed[row2][col2] = false;
		} 
		else {
            system("clear");
			print();
			matches_found++;
			cout << "Match found!\n";
			if (matches_found == total_pairs) { // winning condition 
                auto end_time = chrono::steady_clock::now(); // record end time
                auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time); // calculate duration
				cout << "You won!\n";
                cout << "You won in " << duration.count() << " seconds!\n";
                int time = duration.count();
                return time;
                gameplay = false;
                } 
        }
    }
}

void Board::print(bool show_all) { // have fixed the alignment issue
    cout << '\n'; // add this line
    int cell = 1;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (revealed[i][j] || show_all) {
                cout << setw(5) << board[i][j] << " ";
            } else {
                cout << setw(5) << cell << " ";
            }
            ++cell;
        }
        cout << '\n';
    }
}

vector<vector<string>> Board::createBoard(int board_size) {
    vector<string> list; // board definition 
    if (board_size == 4) {
        list = {"1♠", "1♠", "2♥", "2♥", "3♦", "3♦", "4♣", "4♣", "5♠", "5♠", "6♥","6♥", "7♦", "7♦", "8♣", "8♣"};
    } else if (board_size == 6) {
        list = {"1♠", "1♠", "2♥", "2♥", "3♦", "3♦", "4♣", "4♣", "5♠", "5♠", "6♥","6♥", "7♦", "7♦", "8♣", "8♣", "9♠", "9♠", "10♥", "10♥", "11♦","11♦","12♣", "12♣"," 13♠"," 13♠"," 14♥"," 14♥"," 15♦"," 15♦"," 16♦"," 16♦","17♥","17♥"," 18♥"," 18♥"};
    } else {
        cerr << "Invalid board size\n";
        exit(1);
    }

    shuffle(list.begin(), list.end(), mt19937{random_device{}()}); // shuffling the elements

    vector<vector<string>> board(board_size, vector<string>(board_size)); // vector settings

    int index = 0; // Initializing the board
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            board[i][j] = list[index++];
        }
    }
    return board;
}

int calculateweight(int time, int size) {
    if (size == 4) {
        if (time <= 30) {
            return 2;
        }
    } else {
        if (time <= 60) {
            return 3;
        } else if (time >= 60 && time <= 120) {
            return 2;
        } else {
            return 1;
        }
    }
    return 0;
}

int main() { // shorter main function
    Board game; // define so that it can be accessed
    cout << "Choose the size of the board (4 or 6): ";
    cin >> game.board_size;
    game.board = game.createBoard(game.board_size); // creating board 
    game.revealed.resize(game.board_size, vector<bool>(game.board_size));
    int time = game.play();
    calculateweight(time, game.board_size);
}
