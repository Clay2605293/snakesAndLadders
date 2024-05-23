#include "tablero.h"
#include <iostream>
#include <utility>

using namespace std;

Tablero::Tablero() {
    int tempMatrix[10][10] = {
            {100, 99, 98, 97, 96, 95, 94, 93, 92, 91},
            {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
            {80, 79, 78, 77, 76, 75, 74, 73, 72, 71},
            {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
            {60, 59, 58, 57, 56, 55, 54, 53, 52, 51},
            {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
            {40, 39, 38, 37, 36, 35, 34, 33, 32, 31},
            {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
            {20, 19, 18, 17, 16, 15, 14, 13, 12, 11},
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    };

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            gameMatrix[i][j] = tempMatrix[i][j];
        }
    }

    string tempDisplay[10][10] = {
            {"[100] ", "[ S1] ", "[ 98] ", "[ 97] ", "[ L3] ", "[ 95] ", "[ 94] ", "[ 93] ", "[ 92] ", "[ 91] "},
            {"[ S4] ", "[ 82] ", "[ 83] ", "[ 84] ", "[ 85] ", "[ 86] ", "[ 87] ", "[ 88] ", "[ 89] ", "[ 90] "},
            {"[ 80] ", "[ 79] ", "[ S2] ", "[ 77] ", "[ 76] ", "[ 75] ", "[ L4] ", "[ S3] ", "[ 72] ", "[ L5] "},
            {"[ 61] ", "[ 62] ", "[ 63] ", "[ 64] ", "[ 65] ", "[ 66] ", "[ 67] ", "[ 68] ", "[ 69] ", "[ 70] "},
            {"[ 60] ", "[ 59] ", "[ L3] ", "[ 57] ", "[ 56] ", "[ 55] ", "[ 54] ", "[ 53] ", "[ 52] ", "[ 51] "},
            {"[ 41] ", "[ 42] ", "[ 43] ", "[ L2] ", "[ 45] ", "[ 46] ", "[ L4] ", "[ 48] ", "[ 49] ", "[ 50] "},
            {"[ 40] ", "[ S4] ", "[ 38] ", "[ S2] ", "[ 36] ", "[ 35] ", "[ 34] ", "[ L5] ", "[ S5] ", "[ 31] "},
            {"[ 21] ", "[ 22] ", "[ S1] ", "[ 24] ", "[ L1] ", "[ 26] ", "[ S3] ", "[ 28] ", "[ 29] ", "[ 30] "},
            {"[ 20] ", "[ 19] ", "[ 18] ", "[ 17] ", "[ 16] ", "[ L2] ", "[ 14] ", "[ 13] ", "[ 12] ", "[ 11] "},
            {"[ 01] ", "[ 02] ", "[ L1] ", "[ 04] ", "[ 05] ", "[ 06] ", "[ 07] ", "[ S5] ", "[ 09] ", "[ 10] "}
    };

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrixDisplay[i][j] = tempDisplay[i][j];
        }
    }
}

pair<int, int> Tablero::findNumberInMatrix(int number) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (gameMatrix[i][j] == number) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

void Tablero::printTablero(int pos1, int pos2) {
    const string RED = "\033[31m";
    const string BLUE = "\033[34m";
    const string GREEN = "\033[32m";
    const string RESET = "\033[0m";

    pair<int, int> index1 = findNumberInMatrix(pos1);
    pair<int, int> index2 = findNumberInMatrix(pos2);


    string displayCopy[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            displayCopy[i][j] = matrixDisplay[i][j];
        }
    }

    if (index1 == index2 && index1.first != -1 && index1.second != -1) {
        displayCopy[index1.first][index1.second] = GREEN + "[ BO] " + RESET;
    } else {
        if (index1.first != -1 && index1.second != -1) {
            displayCopy[index1.first][index1.second] = RED + "[ P1] " + RESET;
        }
        if (index2.first != -1 && index2.second != -1) {
            displayCopy[index2.first][index2.second] = BLUE + "[ P2] " + RESET;
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << displayCopy[i][j];
        }
        cout << endl;
    }
}
