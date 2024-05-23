#include <iostream>
#include "tablero.h"
#include "expressGame.h"
using namespace std;


int main() {

    while (true) {
        char option;
        cout << "Menu:" << endl;
        cout << "1. Traditional rules" << endl;
        cout << "2. Express Game" << endl;
        cout << "E. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        option = tolower(option);

        switch (option) {
            case '1':
                cout << "Traditional Game" << endl;
                return 0;
            case '2':
                cout << "Express Game" << endl;
                expressGame();
                return 0;
            case 'e':
                cout << "Thanks for playing." << endl;
                return 0;
            default:
                cout << "Please choose a valid option." << endl;
                break;
        }
    }
    return 0;
}
