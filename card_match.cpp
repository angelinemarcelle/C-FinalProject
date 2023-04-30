#include 'cardmatch.h'
using namespace std;

class Board {
public:
    int board_size;
    bool first_turn = true;
    vector<vector<string>> board;
    vector<vector<bool>> revealed;

    void play_game();
    void display_board(bool show_all = false);
    vector<vector<string>> generate_board(int board_size);
};

void Board::play_game() {
    int matches_found = 0;
    int total_pairs = (board_size * board_size) / 2;
    auto start_time = chrono::steady_clock::now();

    while (true) {
        if (first_turn) {
            display_board(true);
            first_turn = false;
            cout << "Memorise the board for 5 seconds." << endl;
            cout << "Do not press any key while this screen is on!" << endl;
            this_thread::sleep_for(chrono::seconds(5));
            system("clear");
            cout << "From now on, your play time will be recorded!" << endl;
            display_board();
        } else {
            display_board();
        }

        int cell1, cell2;
        cout << "Choose two cells to reveal (1-" << board_size * board_size << "): ";
        cin >> cell1 >> cell2;

        if (cin.fail()) {
            cout << "Invalid input. Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int row1 = (cell1 - 1) / board_size;
        int col1 = (cell1 - 1) % board_size;
        int row2 = (cell2 - 1) / board_size;
        int col2 = (cell2 - 1) % board_size;

        if (cell1 == cell2) {
            cout << "You cannot choose the same cell twice. Try again.\n";
            continue;
        } else if (revealed[row1][col1] || revealed[row2][col2]) {
            cout << "You have already chosen that cell previously. Try again.\n";
            continue;
        }

        revealed[row1][col1] = true;
        revealed[row2][col2] = true;

        if (board[row1][col1] != board[row2][col2]) {
            system("clear");
            display_board(false);
            cout << "No match. Try again.\n" << endl;
            revealed[row1][col1] = false;
            revealed[row2][col2] = false;
        } else {
            system("clear");
            display_board();
            matches_found++;
            cout << "Match found!\n";
            if (matches_found == total_pairs) {
                auto end_time = chrono::steady_clock::now();
                auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);
                cout << "You won!\n";
                cout << "You won in " << duration.count() << " seconds!\n";
                break;
            }
        }
    }
}

void Board::display_board(bool show_all) {
    cout << '\n';
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

vector<vector<string>> Board::generate_board(int board_size) {
    vector<string> list;
    if (board_size == 4) {
        list = {"A1", "A1", "A2", "A2", "A3", "A3", "A4", "A4", "A5", "A5", "A6", "A6", "A7", "A7", "A8", "A8"};
    } else if (board_size == 6) {
        list = {"A1", "A1", "A2", "A2", "A3", "A3", "A4", "A4", "A5", "A5", "A6", "A6", "A7", "A7", "A8", "A8", "A9", "A9", "A10", "A10", "A11", "A11", "A12", "A12", "A13", "A13", "A14", "A14", "A15", "A15", "A16", "A16", "A17", "A17", "A18", "A18"};
    } else {
        cerr << "Invalid board size\n";
        exit(1);
    }shuffle(list.begin(), list.end(), mt19937{random_device{}()});

    vector<vector<string>> board(board_size, vector<string>(board_size));

    int index = 0;
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            board[i][j] = list[index++];
        }
    }
    return board;
}

int main() {
    Board game;
    cout << "Choose the size of the board (4 or 6): ";
    cin >> game.board_size;
    game.board = game.generate_board(game.board_size);
    game.revealed.resize(game.board_size, vector<bool>(game.board_size));
    game.play_game();
}

