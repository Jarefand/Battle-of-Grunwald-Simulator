#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Symulacja.h"
#include <cstdlib>
#include <ctime>

/**
* \mainpage
* \par Projekt z Przedmiotu PJC
* Symulacja bitwy pod Grundwaldem
* \author Albert Duszak
* \date 09.06.2022
* \version 1.0
* \par Kontakt :
* \a 01150947@pw.edu.pl
* \par Cel projektu
* Program powstał w celu realizacji projektu z przedmiotu PJC.
* \n Jego zadaniem jest umożliwienie symulacji walki wojsk.
* \par Instrukcja
* Na początku programu należy podać w konsoli ilość jednostek Polskich i Krzyżackich, następnie symulacja się uruchomi.

*/

/**
* @file Grunwald_1410.cpp
* @brief Główna funkcja programu
*/

int main()
{
	srand(time(NULL));
	
	Symulacja* sym = new Symulacja(1);
	sym->uruchom();
	delete sym;

}


