#ifndef MAIN_H // updated all libraries as of 3rd May 2023
#define MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include "cardMatch.h"
#include "switchCard.h"
#include "fourtyOne.h"

// Players' database
struct Player {
  string name; // player's name
  int money; // player's score
};

#endif
