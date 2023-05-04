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
using namespace std;

class Board { // updated class 30th April 2023
public:
    int board_size;
    static bool first_turn;
    vector<vector<string> > board;
    vector<vector<bool> > revealed;
    int play();
    void print(bool show_all = false);
    vector<vector<string> > createBoard(int board_size);
    int calculateweight(int time, int size);
};

#endif
