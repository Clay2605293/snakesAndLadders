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

void expressGame() {
    Tablero newGame;
    Dice newDice;
    int turn=1;
    int playingPlayer=1;
    int numberOfPlayers=2;
    char option;
    string name1,name2;
    int playerNumber1=1;
    int playerNumber2=2;

    cout<<"In this game the L board squares will increase position by 3, S board squares will decrease position by 3."<<endl;
    cout<<"As soon as a player reaches 100 or over, wins."<<endl;

    Player player1=Player(1);
    Player player2=Player(2);
    player1.setPosition(1);
    player2.setPosition(1);
    cout<<"////////////////////////////////////////////////"<<endl;

    while (player1.getPosition()<=99 or player1.getPosition()<=99){
        cout<<player1.getName()<<" is in position: "<<player1.getPosition()<<endl;
        cout<<player2.getName()<<" is in position: "<<player2.getPosition()<<endl;
        newGame.printTablero(player1.getPosition(),player2.getPosition());
        if (playingPlayer==1){
            cout<<"Turn "<<turn<<endl;
            cout<<"It's "<<player1.getName()<<"'s turn"<<endl;
            cout << "Choose an option"<< endl;
            cout << "R roll dice" << endl;
            cout << "E exit game" << endl;
            cout << "Enter selection: ";
            cin >> option;
            option = tolower(option);
            switch (option) {
                case 'r':{
                    int roll=newDice.diceRoll();
                    int actualpos=player1.getPosition();
                    int newpos=actualpos+roll;
                    cout << "The dice rolled: " << roll <<endl;
                    cout<<player1.getName()<<" goes to square "<<newpos<<endl;
                    player1.setPosition(newpos);
                    turn++;
                    break;
                }
                case 'e':{
                    break;
                }
                default:
                    cout << "Please choose a valid option." << endl;
                    break;
            }
        }

        if (playingPlayer==2){
            cout<<"Turn "<<turn<<endl;
            cout<<"It's "<<player2.getName()<<"'s turn"<<endl;
            cout << "Choose an option"<< endl;
            cout << "R roll dice" << endl;
            cout << "E exit game" << endl;
            cout << "Enter selection: ";
            cin >> option;
            option = tolower(option);
            switch (option) {
                case 'r':{
                    int roll=newDice.diceRoll();
                    int actualpos=player2.getPosition();
                    int newpos=actualpos+roll;
                    cout << "The dice rolled: " << roll <<endl;
                    cout<<player2.getName()<<" goes to square "<<newpos<<endl;
                    player2.setPosition(newpos);
                    turn++;
                    break;
                }
                case 'e':{
                    break;
                }
                default:
                    cout << "Please choose a valid option." << endl;
                    break;
            }
        }
        if (playingPlayer==1){
            playingPlayer=2;
        }
        if (playingPlayer==2){
            playingPlayer=1;
        }

        cout<<"////////////////////////////////////////////////"<<endl;
    }

}




#endif //SERPIENTESESCALERAS_EXPRESSGAME_H
