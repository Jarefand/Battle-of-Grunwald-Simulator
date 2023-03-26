#pragma once
#include "Jednostka.h"

/// @file Pospolite_rusz.h
/// @brief Plik nag³ówkowy klasy Pospolite_rusz

/// @brief Klasa jednostki pospolite ruszenie
class Pospolite_rusz : public Jednostka
{
    double calculateHValue(int row, int col, Pair dest);
public:
    Pospolite_rusz(int x, int y, string arm);
    ~Pospolite_rusz();
    stack <Pair> aStarSearch(int grid[][COL], int xs, int ys, int xd, int yd);
    bool isUnBlocked(int grid[][COL], int row, int col);
};