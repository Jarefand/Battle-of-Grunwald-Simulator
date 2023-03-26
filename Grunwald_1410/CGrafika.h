#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>
#include "Map.h"
#include "Jednostka.h"

using namespace sf;
/// @file CGrafika.h
/// @brief Plik nag�owkowy klasy CGrafika

/// @brief Klasa odpowiadj�ca za wy�wietlanie grafiki
class CGrafika
{
	/// @brief Obiekt odpowiadaj�cy za inicjalizacj� okna grafiki
	RenderWindow* window;
	/// @brief Tekstura terenu las
	Texture las;
	/// @brief Tekstura terenu bagno
	Texture bagno;
	/// @brief Tekstura terenu pole
	Texture pole;
	/// @brief Mapa sprajt�w terenu
	Sprite mapa[ROW][COL];
	/// @brief Tabela zawieraj�ca sprajty jednostek armii polskiej
	vector <Sprite*> armiapol_graf;
	/// @brief Tabela zawieraj�ca sprajty jednostek armii krzy�ackiej
	vector <Sprite*> armiakrzyz_graf;
	/// @brief Tabela zawieracj�ca teksty z ilo�ci� �o�nierzy w jednostkach armii polskiej
	vector <Text*> ilosc_armiapol;
	/// @brief Tabela zawieraj�ca teksty z ilo�ci� �o�nierzy w jednostkach armii krzy�ackiej
	vector <Text*> ilosc_armiakrzyz;
	/// @brief Tekstura polskiej jednostki Pospolite ruszenie
	Texture pospolite_rusz_pol;
	/// @brief Tekstura polskiej jednostki Jazda
	Texture jazda_pol;
	/// @brief Tekstrura polskiej jednostki Zbrojni
	Texture zbrojni_pol;
	/// @brief Tekstura krzy�ackiej jednostki Pospolite ruszenie
	Texture pospolite_rusz_krzyz;
	/// @brief Tekstura krzy�ackiej jednostki Jazda
	Texture jazda_krzyz;
	/// @brief Tekstura krzy�ackiej jednostki Zbrojni
	Texture zbrojni_krzyz;
	/// @brief Czcionka napis�w
	Font czcionka;
	void wczytaj_tekstury(Map* m);
	void czyszczenie();
	void ustaw_tekst(Text* t);
	void aktualizuj(Map* m);
public:
	CGrafika(Map *m, RenderWindow* o);
	~CGrafika();
	void rysuj_oddzialy(Map* m);
	void rysowanie_mapy();
	void wygrana_polacy();
	void wygrana_krzyzacy();

};

