//
// Created by Clay RGH on 22/05/24.
//

#ifndef SERPIENTESESCALERAS_PLAYER_H
#define SERPIENTESESCALERAS_PLAYER_H

#include <string>

using namespace std;

class Player
{
private:
    string name;
    int position;
//
public:
//Constructor
    void setName(string name);
    string getName();
    void setPosition(int name);
    int getPosition();
    Player(int playerNum);
};
#endif //SERPIENTESESCALERAS_PLAYER_H
