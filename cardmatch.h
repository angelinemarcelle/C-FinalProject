#ifndef CARDMATCH_H // updated all libraries as of 30th April 2023
#define CARDMATCH_H

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <chrono> // added for play time calculation
#include <ctime>

class Board { // updated class 30th April 2023
public:
    int board_size;
    bool first_turn = true;
    vector<vector<string>> board;
    vector<vector<bool>> revealed;
    void play();
    void print(bool show_all = false);
    vector<vector<string>> createBoard(int board_size);
    int calculateweight(int time);
};


#endif
