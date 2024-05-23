#include "dice.h"
#include <iostream>
#include <random>

using namespace std;


int Dice::diceRoll()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 6);
    int roll=dis(gen);;
    return roll;
}
