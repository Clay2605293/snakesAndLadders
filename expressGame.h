//
// Created by Clay RGH on 22/05/24.
//

#ifndef SERPIENTESESCALERAS_EXPRESSGAME_H
#define SERPIENTESESCALERAS_EXPRESSGAME_H
#include "tablero.h"
#include "player.h"
#include "dice.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool special_tile(vector<int>& my_list, int target) {
    if (find(my_list.begin(), my_list.end(), target) != my_list.end()) {
        return true;
    } else {
        return false;
    }
}

void expressGame() {
    Tablero newGame;
    Dice newDice;
    int turn = 1;
    int playingPlayer = 1;
    int numberOfPlayers = 2;
    vector<int> snakes = {8,23,27,32,37,39,73,78,81,99};
    vector<int> ladders = {3,1,25,33,44,47,58,71,74,96};
    char option;
    string name1, name2;

    cout << "In this game the L board squares will increase position by 3, S board squares will decrease position by 3." << endl;
    cout << "As soon as a player reaches tile number 100 or over, wins." << endl;

    Player player1 = Player(1);
    Player player2 = Player(2);
    player1.setPosition(1);
    player2.setPosition(1);
    cout << "////////////////////////////////////////////////" << endl;

    while (player1.getPosition() < 100 && player2.getPosition() < 100) {
        cout << player1.getName() << " is in position: " << player1.getPosition() << endl;
        cout << player2.getName() << " is in position: " << player2.getPosition() << endl;
        newGame.printTablero(player1.getPosition(), player2.getPosition());

        cout << "Turn " << turn << endl;
        if (playingPlayer == 1) {
            cout << "It's " << player1.getName() << "'s turn" << endl;
        } else {
            cout << "It's " << player2.getName() << "'s turn" << endl;
        }

        cout << "Choose an option" << endl;
        cout << "R roll dice" << endl;
        cout << "E exit game" << endl;
        cout << "Enter selection: ";
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

                    bool SnakeTile = special_tile(snakes,newPos);
                    bool LadderTile = special_tile(ladders, newPos);

                    //MODIFICADORES
                    if (SnakeTile || LadderTile){
                        if (SnakeTile){
                            cout<<"Uh oh! tile "<<newPos<<" was a SNAKE tile! You slither down to square "<<newPos-3<<endl;
                            newPos-=3;
                        }
                        if (LadderTile){
                            cout<<"Jolly! tile "<<newPos<<" was a LADDER tile! You climb up to square "<<newPos+3<<endl;
                            newPos+=3;
                        }
                        else{
                            continue;
                        }
                    }

                    player1.setPosition(newPos);
                    playingPlayer = 2;
                } else {
                    actualPos = player2.getPosition();
                    newPos = actualPos + roll;
                    cout << "The dice rolled: " << roll << endl;
                    cout << player2.getName() << " goes to square " << newPos << endl;
                    bool SnakeTile = special_tile(snakes,newPos);
                    bool LadderTile = special_tile(ladders, newPos);

                    //MODIFICADORES
                    if (SnakeTile || LadderTile){
                        if (SnakeTile){
                            cout<<"Uh oh! tile "<<newPos<<" was a SNAKE tile! You slither down to square "<<newPos-3<<endl;
                            newPos-=3;
                        }
                        if (LadderTile){
                            cout<<"Jolly! tile "<<newPos<<" was a LADDER tile! You climb up to square "<<newPos+3<<endl;
                            newPos+=3;
                        }
                        else{
                            continue;
                        }
                    }

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

        cout << "////////////////////////////////////////////////" << endl;
    }

    if (player1.getPosition() >= 100) {
        cout << player1.getName() << " wins!" << endl;
    } else if (player2.getPosition() >= 100) {
        cout << player2.getName() << " wins!" << endl;
    }
}

#endif //SERPIENTESESCALERAS_EXPRESSGAME_H