//
// Created by Clay RGH on 23/05/24.
//
#include <string>
#include "player.h"
#include <iostream>
using namespace std;

//Setter Name
void Player::setName(string nam) {
    name = nam;
}
// Getter Name
string Player::getName(){
    return name;
}

//Setter Position
void Player::setPosition(int pos) {
    position = pos;
}
// Getter Name
int Player::getPosition(){
    return position;
}

Player::Player(int playerNum)
{
    string nam;
    cout << "Ingresa el nombre del jugador "<<playerNum<<": ";
    cin >> nam;
    setName(nam);
}
