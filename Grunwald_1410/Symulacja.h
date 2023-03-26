#pragma once
#include <time.h>
#include "Map.h"
#include <stdio.h>
#include "CGrafika.h"
#include <Windows.h>

/// @file Symulacja.h
/// @brief Plik nag�owkowy klasy Symulacja

/// @brief Klasa zajmuj�ca si� obs�ug� symulacji
class Symulacja
{
	/// @brief Obiekt odpowiadaj�cy za wy�wietlnie grafiki
	CGrafika* graf;
	/// @brief Pocz�tkowy czas
	clock_t start;
	/// @brief Aktualny czas
	clock_t now;
	/// @brief R�nica pomi�dzy czasem  aktualnym, a pocz�tkowym
	double elapsed;
	/// @brief czestotliwo�� od�wierzania symulacji
	int czestotliwosc;
	/// @brief Obiekt przechowuj�cy map� oraz wszystkie jednostki si� na niej znajdujace
	Map* mapa;
	/// @brief Obiekt odpowiadaj�cy za okno grafiki
	RenderWindow* okno;
	/// @brief Pocz�tkowa ilos� jednostek w armii polskiej
	int ilosc_jednostek_pol;
	/// @brief Pocz�tkowa ilo�� jednostek w armii krzy�ackiej
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

