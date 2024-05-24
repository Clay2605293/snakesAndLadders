# Snakes and Ladders Game

This is a simple implementation of the classic board game "Snakes and Ladders" in C++.
The game is designed for two players who take turns to roll a dice.
There are 2 rule sets for the game, traditional and express.

In the traditional rules:
The player moves forward by the number of spaces shown on the dice, and if they land at the bottom of a ladder, they move to the top of the ladder.
If they land on the head of a snake, they slide down to the tail of the snake.
The first player to get to the space 100 on the board wins. Any number above 100 will take back the player that amount of tiles.
103 is 3 numbers above 100 so -> 97

Express Rules:
The player moves forward by the number of spaces shown on the dice, and if they land in a ladder, they move forward 3 spaces.
If they land in a snake, they move backward 3 spaces.
The first player to get to the space 100 on the board or above, wins.

## How to Play

1. Clone this folder in a folder in a local machine.
2. Open the project in your preferred C++ IDE. This project was made in Clion, some archives in cmake might produce an error. If so, just delete the extra folder or contact the developer.
3. Build and run the `main.cpp` file.
4. Follow the prompts in the console to play the game.

## Object-Oriented Programming in this Project

This project is an example of Object-Oriented Programming (OOP). It uses classes and objects to represent different components of the game. It also uses constructors, getters, setters and header files to keep everything organized.

- `Tablero` Class: This class represents the game board. It has methods to print the game board and find a number in the reference matrix for the position of the player. It also has a constructor to initialize the game board.

- `Player` Class: This class represents a player in the game. It has methods to construct, set and get names and position in the board.

- `Dice` Class: This class represents the a rolling dice. It has methods to construct and to return random numbers.

- traditionalRules and expressGame files. They contain the logic of the game depending on the selection of the user.

The use of classes, objects and headers in this project makes the code more organized, reusable, and easy to understand.
The use of abstraction was vital to not write unnecesary code and functions for the game.