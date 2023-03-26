#pragma once
#include <array>
#include <chrono>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <tuple>

/// @file Jednostka.h
/// @brief Plik nag��wkowy klasy Jednostka
///@brief Deklaracji ilo�ci wierszy mapy
#define ROW 15
///@brief Deklracja ilo�ci kolumn mapy
#define COL 25
using namespace std;

/// @brief Stworzenie  typu danych do przechowywania pozycji (x,y)
typedef pair<int, int> Pair;


typedef pair<double, pair<int, int> > pPair;

/// @brief Witrualna klasa jednostek
class Jednostka
{
    /// @brief Obrazenia jednostki - sila ataku poszczeg�lnego �o�nierza w jednostce
    int obrazenia;
    /// @brief Obrona jednostki - procent obra�e�, kt�re jednostka ignoruje
    int obrona;
    /// @brief Ilo�� �ycia pojedy�czego �o�nierza z odzia�u
    int zycie;
    /// @brief Liczebno�� jednostki
    int ilosc;
    /// @brief Pozycja x odzia�u
    int poz_x;
    /// @brief Pozycja y odzia�u
    int poz_y;
    /// @brief Zasi�g ataku danego odzia�u
    int zasieg_ataku;
    /// @brief Nazwa armii w kt�rej jest dany odzia�
    string armia;
    /// @brief Nazwa 
    string nazwa;

protected:
    /// @brief Struktura do trzymana niezb�dnych parametr�w do wyliczania �cie�ki algorytmem A*
    struct cell {
        /// @brief pozycja poprzedniego ruchu
        int parent_i, parent_j;
        /// @brief f=g+h
        double f, g, h;
    };
    bool isValid(int row, int col);
    bool isDestination(int row, int col, Pair dest);
    stack <Pair> tracePath(cell cellDetails[][COL], Pair dest);
    virtual double calculateHValue(int row, int col, Pair dest) = 0;
    int get_atk();

public:
    Jednostka(int obr, int ob, int z, int ile, int x, int y, int zas, string arm, string naz);
    void przemieszczenie(Pair kordy);
    bool odbierz_obrazenia(Jednostka* wrog);
    int get_x();
    int get_y();
    int get_zas();
    int get_ilosc();
    string get_armia();
    string get_nazwa();
    virtual stack <Pair> aStarSearch(int grid[][COL], int xs, int ys, int xd, int yd) = 0;
    virtual bool isUnBlocked(int grid[][COL], int row, int col) = 0;
    
};