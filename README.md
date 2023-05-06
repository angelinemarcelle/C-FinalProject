## ENGG1340 Final Project - Group 9
CARD CASINO 🃏💲
---
Welcome to the Card Casino Game. We have 3 mini games for you to play. You can play alone, with a partner, or with 3 other players.
To start, every player will get $1000. Every game will have an initial wager that will be decided in every start of a game. 
Every player can get more money with every win they get by playing the games.

Card Match
---
Our first mini game is Card Match, a single player memory game. In this game, you will be challenged to memorize cards within a limited time frame.

To play, follow these simple steps:
  1. Choose the board size by entering 4 or 6. The bigger the board size, the more cards will be in play.
  2. You will be given 5 seconds to memorize the card elements displayed on the board. 
  3. Enter two numbers that you think are the same.
  4. You could exit the program by enter 'e' when the player's turn start.

If you can successfully complete the game within the allotted time, you will win a prize based on your performance.
  - For the 4x4 board, if you finish in under 120 seconds, you will receive double your initial wager. If you finish in over 120 seconds, you will lose your initial wager.
  - For the 6x6 board, you can win even more! If you finish in under 3 minutes, you will receive three times your initial wager. If you finish in under 3 minutes but over 4 minute, you will receive double your initial wager. If you take over 4 minutes, you will lose your initial wager.

Get your mind ready and play to win more money!

Switch Card
---
Our second mini game is Switch Card, a double player switching game of luck. In this game, two players will compete to get the highest possible value from a combination of 5 cards.

Here's how to play:
  1. First, each player will be given 5 cards randomly chosen from a deck of 52 cards.
  2. Each player will be shown their collection of cards, but keep it hidden from your opponent. You will then have the option to either keep your cards or swap them with random cards generated from the deck.
  3. If you choose to swap your cards, you will be given the option to choose how many and which cards to swap (1-5).
  4. After both players have dealt their cards, both hands are revealed to each other. The player with the higher value of cards will win.

To calculate your score, use the following values:
  - Number cards represent their own numbers.
  - Face cards (Jack, Queen, King) represent 10.
  - Ace represents 11.

If you win, you will receive all the wager from the other player. Since it's a double or nothing game, you'll need luck on your side!

41
---
Our last game is 41, a multiplayer game that you can play with 4 players. In this game, you will be playing alongside 3 other players. The ultimate goal of the game is to get a score of 41 from a combination of 4 cards.

Here's how to play:
  1. To start the game, press "y" and hit enter.
  2. Your cards will be displayed on the screen, along with your current score. You will have the option to either keep your current hand of cards or switch one of your cards with a new card to try and get a better score.
  3. If you want to switch a card, press "y" and then choose the index of the card you want to switch (0-3). If you decide to keep your cards, press "n".
  4. All players will take turns until one player gets a score of 41.
  5. You could exit the program by enter 'e' when the player's turn start.

To calculate your score, use the following values:
  - Number cards represent their own numbers.
  - Face cards (Jack, Queen, King) represent 10.
  - Ace represents 11.

If you win, you will receive the combined wager from all players. Remember, the winner takes it all, so play and strategize well!

---

#Coding Requirements

3.4. File input/output (e.g., for loading/saving game status)

Our Game Casino project features a leaderboard for all players, necessitating file input/output capabilities. We have incorporated a gameData.txt file, which resets whenever a player chooses to reset their funds or introduces a new group of players for gameplay.

3.5. Program codes in multiple files

The project is divided into several parts, each with its respective header file:
1. main.cpp: 
This file acts as the main menu, compiling all mini-games and implementing a uniform casino feature for all players. It manages players' current money, pricing algorithms, and more.
2. cardMatch.cpp: 
This file contains the code for the first single-player mini-game, which involves randomly generating numbers displayed on the screen for a short period. Serving as a simple memorization game, players who win receive prize money as specified in main.cpp.
3. switchCard.cpp: 
This file holds the code for the second mini-game, which also uses random generation. It allows players to decide whether they want to change their hand of cards. Outcomes depend heavily on luck due to the random generation process.
4. fourtyOne.cpp: 
This file contains the code for the third game, designed for 4 players. In this game, players receive a random set of numbers and symbols representing cards. To win, they must create a combination of cards that equals 41.
5. gameData.txt: 
This text file serves as the player leaderboard, storing player names and remaining money. The gameData.txt file can be reset and is periodically read by the main code throughout the game.

#4. List of non-standard C/C++ libraries
  #include <chrono> and #include <ctime> libraries are needed for this project


5. Compilation technique:
To compile the game, use the following command:
**make game**
To run the game, using the following command:
**./main**
To remove the compiled main.cpp, use the following command:
**make clean**
  
---
  
Group members:
1. Song Chanwoo, 3035977628
2. Lukito Angeline Marcelle, 3036037322
3. Garth Winston Patrick, 3036029715
4. Tanujaya Clarence Marvin, 3035993933
5. Elvis Lui Yu On, 3036069193
