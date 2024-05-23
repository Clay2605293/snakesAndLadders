//
// Created by Clay RGH on 22/05/24.
//

#ifndef SERPIENTESESCALERAS_TABLERO_H
#define SERPIENTESESCALERAS_TABLERO_H
#include <utility>
#include <string>
using namespace std;

class Tablero
{
private:
    int gameMatrix[10][10];
    string matrixDisplay[10][10];
//
public:
    //Constructor
    Tablero();
    void printTablero(int pos1, int pos2);
    pair<int, int> findNumberInMatrix(int number);
};

#endif //SERPIENTESESCALERAS_TABLERO_H
