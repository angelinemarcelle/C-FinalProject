#include 'cardmatch.h'
using namespace std;

void printBoard(const vector<vector<string>>& board,
                const vector<vector<bool>>& revealed,
                bool show_all = false) {
    int cell = 1;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (revealed[i][j] || show_all) {
                cout << board[i][j];
                if (board[i][j].size() == 2) {
                    cout << "  ";
                } else {
                    cout << " ";
                }
            } else {
                cout << cell;
                if (cell < 10) {
                    cout << "   ";
                } else {
                    cout << "  ";
                }
            }
            ++cell;
        }
        cout << '\n';
    }
}

int playCardMatch() {
    // setting the variable for size
    int board_size;
    cout << "Choose the size of the board (4 or 6): ";
    cin >> board_size;
    // board definition 
    vector<string> list;
    if (board_size == 4) {
        list = {"A1", "A1", "A2", "A2", "A3", "A3", "A4", "A4", "A5", "A5", "A6","A6", "A7", "A7", "A8", "A8"};
    } else if (board_size == 6) {
        list = {"A1", "A1", "A2", "A2", "A3", "A3", "A4", "A4", "A5", "A5","A6", "A6","A7", "A7", "A8", "A8", "A9", "A9", "A10", "A10", "A11","A11","A12", "A12"," A13"," A13"," A14"," A14"," A15"," A15"," A16","A16","A17"," A17"," A18"," A18"};
    } else {
        cerr << "Invalid board size\n";
        exit(1);
    }

    // shuffling the elements
    shuffle(list.begin(), list.end(), mt19937{random_device{}()});

    // vector settings
    vector<vector<string>> board(board_size, vector<string>(board_size));
    vector<vector<bool>> revealed(board_size, vector<bool>(board_size));

    // Initializing the board
    int index = 0;
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            board[i][j] = list[index++];
        }
    }

   // Game loop
	bool first_turn = true;
    while (true) {
        if (first_turn) {
            printBoard(board, revealed, true);
            first_turn = false;
            cout << "Memorise the picture of the board for 5 seconds" << endl;
            this_thread::sleep_for(chrono::seconds(3));
            system("clear");
            printBoard(board, revealed);
        } 
        else {
        printBoard(board, revealed);
        }

		int cell1, cell2;
		cout << "Choose two cells to reveal (1-" << board_size * board_size << "): ";
		cin >> cell1 >> cell2;
        system("clear");
        

		// Check if the user has chosen the same cell twice
		if (cell1 == cell2) {
			cout << "You cannot choose the same cell twice. Try again.\n";
			continue;
		}

		// Convert cell numbers to board indices
		int row1 = (cell1 - 1) / board_size;
        int col1 = (cell1 - 1) % board_size;
        int row2 = (cell2 - 1) / board_size;
        int col2 = (cell2 - 1) % board_size;

		// Reveal the cells
		revealed[row1][col1] = true;
		revealed[row2][col2] = true;

		// Check if the cells match
		if (board[row1][col1] != board[row2][col2]) {
			printBoard(board, revealed, false);
			cout << "No match. Try again.\n" << endl;
			revealed[row1][col1] = false;
			revealed[row2][col2] = false;
		} 
		else {
			printBoard(board, revealed);
			cout << "Match found!\n";
		}
	}
}
