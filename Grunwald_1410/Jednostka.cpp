#include "Jednostka.h"

/// @file Jednostka.cpp
/// @brief plik Ÿród³owy klasy Jednostka

/// @brief Konstruktor klasy Jednostka
/// @param obr wartoœæ obra¿eñ ¿o³nierza w oddziale
/// @param ob wartoœæ obrony odzia³u
/// @param z wartœæ ¿ycia pojedyñczego ¿o³nierza z jednostki
/// @param ile iloœæ ¿o³nierzy w jednostce
/// @param x pozycja x odzia³u
/// @param y pozycja y odzia³u
/// @param zas zasiêg jednostki
/// @param arm armia do której nale¿y oddzia³
/// @param naz nazwa danej jednostki
Jednostka::Jednostka(int obr, int ob, int z, int ile, int x, int y, int zas, string arm, string naz)
{
    obrazenia = obr;
    obrona = ob;
    zycie = z;
    ilosc = ile;
    poz_x = x;
    poz_y = y;
    zasieg_ataku = zas;
    armia = arm;
    nazwa = naz;
}

/// @brief Zwraca zasiêg danej jednostki
/// @return Zasiêg odzia³u
int Jednostka::get_zas()
{
    return zasieg_ataku;
}

/// @brief Zwraca pozycjê x odzia³u
/// @return Pozycja x odzia³u
int Jednostka::get_x()
{
    return poz_x;
}

/// @brief Zwraca pozycjê y odzia³u
/// @return Pozycja y oddzia³u
int Jednostka::get_y()
{
    return poz_y;
}

/// @brief Zwraca nazwê armii do, której nale¿y jednostka
/// @return Nazwa armii
string Jednostka::get_armia()
{
    return armia;
}

/// @brief Zwraca nazwê danej jednostki
/// @return Nazwa danej jednostki
string Jednostka::get_nazwa()
{
    return nazwa;
}

/// @brief Zwraca obra¿enia jednego ¿o³nierza w jednostce
/// @return Wartoœæ obra¿eñ ¿o³nierza w oddziale
int Jednostka::get_atk()
{
    return obrazenia;
}

/// @brief Zwraca iloœæ ¿o³nierzy w jednostce
/// @return Iloœæ ¿o³nierzy w jednostce
int Jednostka::get_ilosc()
{
    return ilosc;
}

/// @brief Odbiera obra¿enia jednostce
/// @param wrog Odzia³, który zadaje obra¿enia(atakuje) 
/// @return Zwraca 0, gdy jednostka nie przy¿yje(straci wszystkich ¿o³nierzy)
bool Jednostka::odbierz_obrazenia(Jednostka* wrog)
{
    ilosc = ((zycie * ilosc) - (rand() % 10 + 75) * ((100 - obrona) * wrog->get_atk() * wrog->get_ilosc() / 10000)) / zycie;

    if (ilosc < 1)
    {
        return 0;
    }
    return 1;
}

/// @brief Sprawdza czy podana pozycja mieœcie siê na mapie
/// @param row Pozycja x
/// @param col Pozycja y
/// @return Czy pozycja jest na mapie
bool Jednostka::isValid(int row, int col)
{
    // Returns true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) && (col >= 0)
        && (col < COL);
}

/// @brief Sprawdza czy osi¹gnieto cel
/// @param row Pozycja x
/// @param col Pozycja y
/// @param dest Pozycja celu
/// @return Czy podane pozycjê x,y zagdzaj¹ sie z pozycj¹ celu
bool Jednostka::isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}

/// @brief Tworzy œcie¿kê do celu
/// @param cellDetails 
/// @param dest Pozycja celu 
/// @return Scie¿ka do celu w postaci stosu
stack <Pair> Jednostka::tracePath(cell cellDetails[][COL], Pair dest)
{
    int row = dest.first;
    int col = dest.second;

    stack<Pair> Path;
    stack<Pair> Path1;

    while (!(cellDetails[row][col].parent_i == row
        && cellDetails[row][col].parent_j == col)) {
        Path.push(make_pair(row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    Path.push(make_pair(row, col));
    Path1 = Path;
    return Path1;
}

/// @brief Powoduje przemieszczenie jednostki do danej pozycji
/// @param kordy Wpó³rzêdne do których ma siê przenieœæ jednostka
void Jednostka::przemieszczenie(Pair kordy)
{
    pair<int, int> p = kordy;
    poz_y = kordy.first;
    poz_x = kordy.second;
}
