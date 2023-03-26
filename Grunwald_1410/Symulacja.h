#pragma once
#include <time.h>
#include "Map.h"
#include <stdio.h>
#include "CGrafika.h"
#include <Windows.h>

/// @file Symulacja.h
/// @brief Plik nag³owkowy klasy Symulacja

/// @brief Klasa zajmuj¹ca siê obs³ug¹ symulacji
class Symulacja
{
	/// @brief Obiekt odpowiadaj¹cy za wyœwietlnie grafiki
	CGrafika* graf;
	/// @brief Pocz¹tkowy czas
	clock_t start;
	/// @brief Aktualny czas
	clock_t now;
	/// @brief Ró¿nica pomiêdzy czasem  aktualnym, a pocz¹tkowym
	double elapsed;
	/// @brief czestotliwoœæ odœwierzania symulacji
	int czestotliwosc;
	/// @brief Obiekt przechowuj¹cy mapê oraz wszystkie jednostki siê na niej znajdujace
	Map* mapa;
	/// @brief Obiekt odpowiadaj¹cy za okno grafiki
	RenderWindow* okno;
	/// @brief Pocz¹tkowa ilosæ jednostek w armii polskiej
	int ilosc_jednostek_pol;
	/// @brief Pocz¹tkowa iloœæ jednostek w armii krzy¿ackiej
	int ilosc_jednostek_krzyz;
	void pobranie_danych();
	void dodawanie_jednostek();
	void odswierz_cz();
	void odswierz();
public:
	Symulacja(int cze);
	~Symulacja();
	bool koniec_gry();
	void uruchom();
};

