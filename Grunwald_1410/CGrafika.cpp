
#include "CGrafika.h"

/// @file CGrafika.cpp
/// @brief Plik Ÿród³owy klasy CGrafika

/// @brief Konstruktor klasy CGrafika
/// @param m Obiekt przechowuj¹cy mapê oraz wszystkie jednostki siê niej znajdujace
/// @param o Obiekt odpowiadaj¹cy za okno grafiki
CGrafika::CGrafika(Map* m, RenderWindow* o)
{
	if (!this->las.loadFromFile("Tekstury/las.png")) { cout << "Brak obrazu w folderze Tekstury" << endl; }
	if (!this->pole.loadFromFile("Tekstury/pole.png")) { cout << "Brak obrazu w folderze Tekstury" << endl; }
	if (!this->bagno.loadFromFile("Tekstury/bagno.png")) { cout << "Brak obrazu w folderze Tekstury" << endl; }
	wczytaj_tekstury(m);

	window = o;

	if (!this->pospolite_rusz_pol.loadFromFile("Tekstury/pos_rusz_pol.png")) { cout << "Brak obrazu w folderze Tekstury" << endl; }
	if (!this->pospolite_rusz_krzyz.loadFromFile("Tekstury/pos_rusz_krzyz.png")) { cout << "Brak obrazu w folderze Tekstury" << endl; }
	if (!this->jazda_pol.loadFromFile("Tekstury/jazda_pol.png")) { cout << "Brak obrazu w folderze Tekstury" << endl; }
	if (!this->jazda_krzyz.loadFromFile("Tekstury/jazda_krzyz.png")) { cout << "Brak obrazu w folderze Tekstury" << endl; }
	if (!this->zbrojni_pol.loadFromFile("Tekstury/zbrojny_pol.png")) { cout << "Brak obrazu w folderze Tekstury" << endl; }
	if (!this->zbrojni_krzyz.loadFromFile("Tekstury/zbrojny_krzyz.png")) { cout << "Brak obrazu w folderze Tekstury" << endl; }
	if (!this->czcionka.loadFromFile("Czcionki/arial.ttf")) { cout << "Brak czcionki w folderze Czcionki" << endl; }

}

/// @brief Przypisanie tekstur terenom na mapie
/// @param m Obiekt przechowuj¹cy mapê oraz wszystkie jednostki siê niej znajdujace
void CGrafika::wczytaj_tekstury(Map* m)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			switch (m->get_grid(i, j))
			{
			case 0:
				mapa[i][j].setTexture(las);
				break;
			case 1:
				mapa[i][j].setTexture(pole);
				break;
			case 2:
				mapa[i][j].setTexture(bagno);
				break;

			}
		}
	}

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			mapa[i][j].setPosition(j * 64, i * 64);
		}
	}
}

/// @brief Rysowanie mapy terenu
void CGrafika::rysowanie_mapy()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			window->draw(mapa[i][j]);
		}
	}
}

/// @brief Dekonstruktor klasy CGrafika
CGrafika::~CGrafika()
{
	czyszczenie();
}

/// @brief Czyszczenie tablic w klasie CGrafika
void CGrafika::czyszczenie()
{
	if (!armiapol_graf.empty())
	{
		for (int i = 0; i < armiapol_graf.size(); i++)
		{
			delete armiapol_graf[i];
		}

	}
	armiapol_graf.clear();

	if (!armiakrzyz_graf.empty())
	{
		for (int i = 0; i < armiakrzyz_graf.size(); i++)
		{
			delete armiakrzyz_graf[i];
		}

	}
	armiakrzyz_graf.clear();

	if (!ilosc_armiapol.empty())
	{
		for (int i = 0; i < ilosc_armiapol.size(); i++)
		{
			delete ilosc_armiapol[i];
		}

	}
	ilosc_armiapol.clear();

	if (!ilosc_armiakrzyz.empty())
	{
		for (int i = 0; i < ilosc_armiakrzyz.size(); i++)
		{
			delete ilosc_armiakrzyz[i];
		}

	}
	ilosc_armiakrzyz.clear();
}

/// @brief Akutalizacja pozycji tekstur jednostek na mapie
/// @param m Obiekt przechowuj¹cy mapê oraz wszystkie jednostki siê niej znajdujace
void CGrafika::aktualizuj(Map* m)
{
	czyszczenie();
	for (int  i = 0; i < m->getarmia_pol().size(); i++)
	{
		armiapol_graf.push_back(new Sprite);
		ilosc_armiapol.push_back(new Text);
		ustaw_tekst(ilosc_armiapol[i]);
		ilosc_armiapol[i]->setString(to_string(m->getarmia_pol()[i]->get_ilosc()));
		ilosc_armiapol[i]->setPosition(m->getarmia_pol()[i]->get_x() * 64 + 32 , m->getarmia_pol()[i]->get_y() * 64 + 32 );


		if(m->getarmia_pol()[i]->get_nazwa() == "Pospolite_rusz")
		{
			armiapol_graf[i]->setTexture(pospolite_rusz_pol);
		}
		else if(m->getarmia_pol()[i]->get_nazwa() == "Jazda")
		{
			armiapol_graf[i]->setTexture(jazda_pol);
		}
		else if (m->getarmia_pol()[i]->get_nazwa() == "Zbrojni")
		{
			armiapol_graf[i]->setTexture(zbrojni_pol);
		}
		armiapol_graf[i]->setPosition(m->getarmia_pol()[i]->get_x()*64 - 25, m->getarmia_pol()[i]->get_y()*64 - 30);

	}

	for (int i = 0; i < m->getarmia_krzyz().size(); i++)  
	{
		armiakrzyz_graf.push_back(new Sprite);

		ilosc_armiakrzyz.push_back(new Text);
		ustaw_tekst(ilosc_armiakrzyz[i]);
		ilosc_armiakrzyz[i]->setString(to_string(m->getarmia_krzyz()[i]->get_ilosc()));
		ilosc_armiakrzyz[i]->setPosition(m->getarmia_krzyz()[i]->get_x() * 64 + 32, m->getarmia_krzyz()[i]->get_y() * 64 + 32);

		if(m->getarmia_krzyz()[i]->get_nazwa() == "Pospolite_rusz")
		{
			armiakrzyz_graf[i]->setTexture(pospolite_rusz_krzyz);
		}
		else if (m->getarmia_krzyz()[i]->get_nazwa() == "Jazda")
		{
			armiakrzyz_graf[i]->setTexture(jazda_krzyz);
		}  
		else if (m->getarmia_krzyz()[i]->get_nazwa() == "Zbrojni")
		{
			armiakrzyz_graf[i]->setTexture(zbrojni_krzyz);
		}
		armiakrzyz_graf[i]->setPosition(m->getarmia_krzyz()[i]->get_x() *64 - 25  , m->getarmia_krzyz()[i]->get_y() * 64 - 30 );
;
	}

}

/// @brief Rysowanie tekstur jednostek w oknie
/// @param m Obiekt przechowuj¹cy mapê oraz wszystkie jednostki siê niej znajdujace
void CGrafika::rysuj_oddzialy(Map* m)
{
	aktualizuj(m);
	if (!armiapol_graf.empty())
	{
		for (int i = 0; i < armiapol_graf.size(); i++)
		{
			window->draw(*armiapol_graf[i]);
			window->draw(*ilosc_armiapol[i]);
		}
	}

	if (!armiakrzyz_graf.empty())
	{
		for (int i = 0; i < armiakrzyz_graf.size(); i++)
		{
			window->draw(*armiakrzyz_graf[i]);
			window->draw(*ilosc_armiakrzyz[i]);
		}
	}
}

/// @brief Ustawienie parametrów tekstu
/// @param t Tekst 
void CGrafika::ustaw_tekst(Text* t)
{
	t->setFont(czcionka);
	t->setCharacterSize(12);
	t->setStyle(Text::Style::Bold);
	t->setFillColor(Color::White);
}

/// @brief Rysowanie napisu "Zwyciêtswo Polaków"
void CGrafika::wygrana_polacy()
{
	Text tekst;
	tekst.setFont(czcionka);
	tekst.setCharacterSize(88);
	tekst.setStyle(Text::Style::Bold);
	tekst.setFillColor(Color::Red);
	tekst.setString(L"Zwyciêstwo Polaków!!!");
	tekst.setPosition(300,400);
	window->draw(tekst);

}

/// @brief Rysowanie napisu "Zwyciêstwo Krzy¿aków'
void CGrafika::wygrana_krzyzacy()
{
	Text tekst;
	tekst.setFont(czcionka);
	tekst.setCharacterSize(102);
	tekst.setStyle(Text::Style::Bold);
	tekst.setFillColor(Color::Black);
	tekst.setString(L"Zwyciêstwo Krzy¿aków!!!");
	tekst.setPosition(300, 400);
	window->draw(tekst);
}