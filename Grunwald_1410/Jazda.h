#pragma once
#include "Jednostka.h"
#include <cstdlib>
#include <ctime>
/// @file Jazda.h
/// @brief Plik nag³ówkowy klasy Jazda

/// @brief Klasa jednostki jazda
class Jazda : public Jednostka
{
    double calculateHValue(int row, int col, Pair dest);
public:
    Jazda(int x, int y, string arm);
    ~Jazda();
    stack <Pair> aStarSearch(int grid[][COL], int xs, int ys, int xd, int yd);
    bool isUnBlocked(int grid[][COL], int row, int col);
};

