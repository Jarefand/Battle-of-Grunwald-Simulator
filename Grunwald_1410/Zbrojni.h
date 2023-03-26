#pragma once
#include "Jednostka.h"
/// @file Zbrojni.h
/// @brief Plik nag³ówkowy klasy Zbrojni

/// @brief Klasa jednostki zbrojni
class Zbrojni : public Jednostka
{
    double calculateHValue(int row, int col, Pair dest);
public:
    Zbrojni(int x, int y, string arm);
    ~Zbrojni();
    stack <Pair> aStarSearch(int grid[][COL], int xs, int ys, int xd, int yd);
    bool isUnBlocked(int grid[][COL], int row, int col);
};
