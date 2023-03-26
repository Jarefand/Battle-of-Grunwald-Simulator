#include "Jednostka.h"

/// @file Jednostka.cpp
/// @brief plik �r�d�owy klasy Jednostka

/// @brief Konstruktor klasy Jednostka
/// @param obr warto�� obra�e� �o�nierza w oddziale
/// @param ob warto�� obrony odzia�u
/// @param z wart�� �ycia pojedy�czego �o�nierza z jednostki
/// @param ile ilo�� �o�nierzy w jednostce
/// @param x pozycja x odzia�u
/// @param y pozycja y odzia�u
/// @param zas zasi�g jednostki
/// @param arm armia do kt�rej nale�y oddzia�
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

/// @brief Zwraca zasi�g danej jednostki
/// @return Zasi�g odzia�u
int Jednostka::get_zas()
{
    return zasieg_ataku;
}

/// @brief Zwraca pozycj� x odzia�u
/// @return Pozycja x odzia�u
int Jednostka::get_x()
{
    return poz_x;
}

/// @brief Zwraca pozycj� y odzia�u
/// @return Pozycja y oddzia�u
int Jednostka::get_y()
{
    return poz_y;
}

/// @brief Zwraca nazw� armii do, kt�rej nale�y jednostka
/// @return Nazwa armii
string Jednostka::get_armia()
{
    return armia;
}

/// @brief Zwraca nazw� danej jednostki
/// @return Nazwa danej jednostki
string Jednostka::get_nazwa()
{
    return nazwa;
}

/// @brief Zwraca obra�enia jednego �o�nierza w jednostce
/// @return Warto�� obra�e� �o�nierza w oddziale
int Jednostka::get_atk()
{
    return obrazenia;
}

/// @brief Zwraca ilo�� �o�nierzy w jednostce
/// @return Ilo�� �o�nierzy w jednostce
int Jednostka::get_ilosc()
{
    return ilosc;
}

/// @brief Odbiera obra�enia jednostce
/// @param wrog Odzia�, kt�ry zadaje obra�enia(atakuje) 
/// @return Zwraca 0, gdy jednostka nie przy�yje(straci wszystkich �o�nierzy)
bool Jednostka::odbierz_obrazenia(Jednostka* wrog)
{
    ilosc = ((zycie * ilosc) - (rand() % 10 + 75) * ((100 - obrona) * wrog->get_atk() * wrog->get_ilosc() / 10000)) / zycie;

    if (ilosc < 1)
    {
        return 0;
    }
    return 1;
}

/// @brief Sprawdza czy podana pozycja mie�cie si� na mapie
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

/// @brief Sprawdza czy osi�gnieto cel
/// @param row Pozycja x
/// @param col Pozycja y
/// @param dest Pozycja celu
/// @return Czy podane pozycj� x,y zagdzaj� sie z pozycj� celu
bool Jednostka::isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}

/// @brief Tworzy �cie�k� do celu
/// @param cellDetails 
/// @param dest Pozycja celu 
/// @return Scie�ka do celu w postaci stosu
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
/// @param kordy Wp�rz�dne do kt�rych ma si� przenie�� jednostka
void Jednostka::przemieszczenie(Pair kordy)
{
    pair<int, int> p = kordy;
    poz_y = kordy.first;
    poz_x = kordy.second;
}
