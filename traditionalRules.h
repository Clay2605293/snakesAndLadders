//
// Created by Clay RGH on 22/05/24.
//

#ifndef SERPIENTESESCALERAS_TRADITIONALRULES_H
#define SERPIENTESESCALERAS_TRADITIONALRULES_H
#include "tablero.h"
#include "player.h"
#include "dice.h"
#include <iostream>
#include <string>

#include <map>
map<int, int> snakes = {{99, 23}, {78, 37}, {73, 27}, {81, 39}, {32, 8}};
map<int, int> ladders = {{3, 25}, {15, 44}, {58, 96}, {47, 74}, {33, 71}};
string line = "========================================================";


int handleSnakesAndLadders(int currentPosition) {
    if(currentPosition>100) {
        currentPosition = 100 - (currentPosition - 100);
    }

    if (snakes.find(currentPosition) != snakes.end()) {
        cout<<"You fell into a snake. Down you go!"<<endl;
        cout<<"Your new position is: "<<snakes[currentPosition]<<endl;
        return snakes[currentPosition];
    }
    if (ladders.find(currentPosition) != ladders.end()) {
        cout<<"You fell into a ladder. Up you go!"<<endl;
        cout<<"Your new position is: "<<ladders[currentPosition]<<endl;
        return ladders[currentPosition];
    }

    return currentPosition;
};


void tradGame() {
    Tablero newGame;
    Dice newDice;
    int turn = 1;
    int playingPlayer = 1;
    int numberOfPlayers = 2;
    char option;
    string name1, name2;

    cout << line << endl << endl <<"In this game of you fall into a ladder you'll go up until the end of it." << endl;
    cout << "If you fall into a snake you'll go down until the end of it." << endl;
    cout << "You have to land exactly in square 100 to win" << endl << endl << line << endl;

    Player player1 = Player(1);
    Player player2 = Player(2);
    player1.setPosition(1);
    player2.setPosition(1);

    while (player1.getPosition() != 100 && player2.getPosition() !=  100) {
        cout << player1.getName() << " is in position: " << player1.getPosition() << endl;
        cout << player2.getName() << " is in position: " << player2.getPosition() << endl << line << endl;
        newGame.printTablero(player1.getPosition(), player2.getPosition());

        cout << line << endl <<  "Turn " << turn << endl;
        if (playingPlayer == 1) {
            cout << "It's " << player1.getName() << "'s turn" << endl;
        } else {
            cout << "It's " << player2.getName() << "'s turn" << endl;
        }

        cout << "Choose an option" << endl;
        cout << "\t-R roll dice" << endl;
        cout << "\t-E exit game" << endl;
        cout << "\t-Enter selection: ";
        cin >> option;
        option = tolower(option);
        int roll, actualPos, newPos;
        switch (option) {
            case 'r':
                roll = newDice.diceRoll();
                if (playingPlayer == 1) {
                    actualPos = player1.getPosition();
                    newPos = actualPos + roll;
                    cout << "The dice rolled: " << roll << endl;
                    cout << player1.getName() << " goes to square " << newPos << endl;
                    newPos=handleSnakesAndLadders(newPos);
                    player1.setPosition(newPos);
                    playingPlayer = 2;
                } else {
                    actualPos = player2.getPosition();
                    newPos = actualPos + roll;
                    cout << "The dice rolled: " << roll << endl;
                    cout << player2.getName() << " goes to square " << newPos << endl;
                    newPos=handleSnakesAndLadders(newPos);
                    player2.setPosition(newPos);
                    playingPlayer = 1;
                }
                turn++;
                break;
            case 'e':
                cout << "Game exited." << endl;
                return;
            default:
                cout << "Please choose a valid option." << endl;
                break;
        }
        cout << endl << line << endl;
    }

    if (player1.getPosition() == 100) {
        cout << player1.getName() << " wins!" << endl;
    } else if (player2.getPosition() == 100) {
        cout << player2.getName() << " wins!" << endl;
    }
}


#endif //SERPIENTESESCALERAS_TRADITIONALRULES_H
