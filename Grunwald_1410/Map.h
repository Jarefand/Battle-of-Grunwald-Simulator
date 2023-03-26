#pragma once
#include "Pospolite_rusz.h"
#include "Jazda.h"
#include "Jednostka.h"
#include <vector>
#include "math.h"
#include "Zbrojni.h"
#include <cstdlib>
#include <ctime>

/// @file Map.h
/// @brief Plik nag³ówkowy klasy Map

/// @brief Klasa zawieraj¹ca mapê oraz przechowuj¹ca wszystkie obiekty znajdujace siê na mapie
class Map
{
    /// @brief Tablica przechowuj¹ca jednostki armi Polskiej
    vector <Jednostka*> armia_pol;
    /// @brief Tablica przechowuj¹ca jednostki armi Krzy¿ackiej
    vector <Jednostka*> armia_krzyz;
    /// @brief Tablica przechowuj¹ca w postaci liczbowej rodzaje terenu. 0 - las, 1 - pole, 2 - bagno
    int grid[ROW][COL]
        = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1 ,1},
            { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
            { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1},
            { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1},
            { 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1},
            { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 2, 1, 2, 0, 1},
            { 1, 1, 1, 2, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 2, 1, 1, 2, 1, 2},
            { 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 2, 1},
            { 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 0, 2, 1, 2, 2},
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 0, 0, 2, 1, 1, 1},
            { 1, 1, 0, 1, 1, 1, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 2, 0, 1, 1, 0, 1, 1, 1, 1},
            { 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 2, 0, 1, 1, 1, 1, 1, 1},
            { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };
	/// @brief Tablica przechowuj¹ca w postaci liczbowej rodzaje terenu, b¹dŸ jednostki na niej siê znajduj¹ce
	int mapa_walki[ROW][COL];
    void ustawienie_jednostek(Jednostka* oddzial);
	
public:
    ~Map();
    void dodajJednostkePolsce();
    void dodajJednostkeKrzyzakom();
    vector <Jednostka*> getarmia_pol();
    vector <Jednostka*> getarmia_krzyz();
	void aktualizuj_mape_walki();
	stack <Pair> znajdz_przeciwnika(Jednostka* oddzial);
    bool czy_w_zasiegu(Jednostka* oddzial);
    int get_grid(int i, int j);


};